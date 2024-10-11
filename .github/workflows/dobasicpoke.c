import sys
import numpy as np
import darc
import FITS
import time

# Initialize number of frames and poke value
nfr = 1
if len(sys.argv) > 1:
    nfr = int(sys.argv[1])
pokeval = 10.0
if len(sys.argv) > 2:
    pokeval = float(sys.argv[2])

print("Have you set into calibration mode and taken reference slopes?")
d = darc.Control()

# Validate the shape of rmx
rmx = d.Get("rmx")
if rmx.ndim != 2:
    raise ValueError("rmx is not a 2D array. Expected shape: (nacts, nslopes)")

nacts, nslopes = rmx.shape
pmx = np.zeros((nacts, 1), np.float32)  # Initialize pmx as a 2D array with one column

d.Set("addActuators", 0)
actuators = np.ones((nacts,), np.float32) * 32768.0

for i in range(nacts):
    print(f"Poking {i}")
    actuators[i] = 32768.0 + pokeval
    d.Set("actuators", actuators)
    time.sleep(1.5)
    
    # Ensure rtcCentBuf is a 2D array and compute slopes
    sl_data = d.SumData("rtcCentBuf", nfr)
    if sl_data.ndim != 2:
        raise ValueError("rtcCentBuf is not a 2D array.")

    sl = sl_data[0] / nfr / pokeval
    pmx[i] = sl  # Store slopes in pmx
    actuators[i] = 32768.0  # Reset actuator

# Finalize actuator settings and write output files
d.Set("actuators", actuators)
FITS.Write(pmx, "pmx.fits")
rmx = -np.linalg.pinv(pmx, 0.1).T  # Compute pseudo-inverse of pmx
FITS.Write(rmx, "rmx.fits")
if not d.Set("rmx", rmx):
    raise RuntimeError("Failed to set rmx in darc")

print("Saved pmx.fits, rmx.fits and set rmx into darc")
