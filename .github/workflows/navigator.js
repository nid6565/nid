import React from "react";
import { createStackNavigator } from "react-navigation-stack";
import { createBottomTabNavigator } from "react-navigation-tabs";
import HomeScreen from "../screens/HomeScreen";
import SectionScreen from "../screens/SectionScreen";
import Ionicons from "@expo/vector-icons/Ionicons";

const activeColor = "#4775f2";
const inactiveColor = "#b8bece";

const HomeStack = createStackNavigator(
  {
    Home: HomeScreen,
    Section: SectionScreen,
  },
  {
    defaultNavigationOptions: {
      headerShown: false,
    },
  }
);

HomeStack.navigationOptions = ({ navigation }) => {
  const routeName = navigation.state.routes[navigation.state.index].routeName;
  const tabBarVisible = routeName === "Home"; // Show tab bar only on Home screen

  return {
    tabBarVisible,
    tabBarLabel: "Home",
    tabBarIcon: ({ focused }) => (
      <Ionicons
        name="ios-home"
        size={26}
        color={focused ? activeColor : inactiveColor}
      />
    ),
  };
};

const CoursesStack = createStackNavigator({
  Courses: SectionScreen,
});

CoursesStack.navigationOptions = {
  tabBarLabel: "Course",
  tabBarIcon: ({ focused }) => (
    <Ionicons
      name="ios-albums"
      size={26}
      color={focused ? activeColor : inactiveColor}
    />
  ),
};

const ProjectsStack = createStackNavigator({
  Projects: SectionScreen,
});

ProjectsStack.navigationOptions = {
  tabBarLabel: "Projects",
  tabBarIcon: ({ focused }) => (
    <Ionicons
      name="ios-folder"
      size={26}
      color={focused ? activeColor : inactiveColor}
    />
  ),
};

const TabNavigator = createBottomTabNavigator({
  HomeStack,
  CoursesStack,
  ProjectsStack,
});

export default TabNavigator;
