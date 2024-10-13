import os
import glob
import argparse
import cv2

def parse_target_size(target_size_str):
    """Parses the target size string into a tuple of two integers (width, height)."""
    try:
        width, height = map(int, target_size_str.strip('()').split(','))
        if width <= 0 or height <= 0:
            raise ValueError
        return (width, height)
    except (ValueError, AttributeError):
        raise ValueError("Invalid target size format. Use --target-size (width,height), e.g., --target-size (640,480)")

def resize_image(image_path, target_size):
    """Resizes an image to the specified target size.

    Args:
        image_path: Path to the image file.
        target_size: A tuple containing the desired width and height.

    Returns:
        The resized image.

    Raises:
        FileNotFoundError: If the image file is not found.
    """
    img = cv2.imread(image_path)
    if img is None:
        raise FileNotFoundError(f"Image not found at {image_path}")
    resized_img = cv2.resize(img, target_size)
    return resized_img

def main():
    parser = argparse.ArgumentParser(description="Resize images in a directory to a specified size.")
    parser.add_argument("--raw-dir", help="Directory path to raw images.", default="./data/raw", type=str)
    parser.add_argument("--save-dir", help="Directory path to save resized images.", default="./data/images", type=str)
    parser.add_argument("--ext", help="Raw image files extension to resize.", default="jpg", type=str)
    parser.add_argument("--target-size", required=True, help="Target size (width,height), e.g., --target-size (640,480)", type=str)
    args = parser.parse_args()

    raw_dir = args.raw_dir
    save_dir = args.save_dir
    ext = args.ext
    target_size = parse_target_size(args.target_size)

    if not os.path.exists(save_dir):
        os.makedirs(save_dir)

    fnames = glob.glob(os.path.join(raw_dir, f"*.{ext}"))
    print(f"{len(fnames)} files to resize from directory `{raw_dir}` to target size: {target_size}")

    for i, fname in enumerate(fnames):
        try:
            resized_img = resize_image(fname, target_size)
            new_fname = os.path.join(save_dir, f"{i}.{ext}")
            cv2.imwrite(new_fname, resized_img)
            print(f"Resized and saved: {new_fname}")
        except FileNotFoundError as e:
            print(f"Error: {e}")
        except Exception as e:
            print(f"An error occurred while processing {fname}: {e}")

    print(f"\nDone resizing {len(fnames)} files.\nSaved to directory: `{save_dir}`")

if __name__ == "__main__":
    main()
