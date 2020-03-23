# Assignment 3
**Due by 11:59pm on Monday, 2/24/2020** <br />
**Demo due by 11:59pm on Monday, 3/9/2020**

In this assignment, we'll adapt our weather app to gracefully deal with transitions in the activity lifecycle by implementing the `ViewModel` architecture.  You'll also add some basic user preferences to the app.

There are a few different tasks associated with this assignment, described below.  This repository provides you with some starter code that implements the connected weather app from assignment 2, plus a few extra layout bells and whistles.

**NOTE: make sure to add your own API key in [`OpenWeatherMapUtils.java`](app/src/main/java/com/example/android/lifecycleweather/utils/OpenWeatherMapUtils.java#L30) to make the app work.**

## 1. Implement the ViewModel architecture

One thing you might notice is that when you do things like rotate your device when viewing the main activity, the activity is recreated, resulting in a new network call to fetch the same weather forecast data.  You can know this is happening because the loading indicator will be displayed, indicating that the `AsyncTask` for fetching forecast data from OpenWeatherMap is running.

Your first task in this assignment is to fix this problem by moving the app's current `AsyncTask` behind a `ViewModel` to make our activity better cope with lifecycle transitions.  Doing this will involve a few different sub-tasks:

  * Implement a Repository class to perform the data operations associated with communicating with the OpenWeatherMap API.  This Repository class will invoke the `AsyncTask` to fetch forecast data when needed, and it will be the location where the forecast data is ultimately stored within the app (as `LiveData`).  Make sure to implement a reasonable caching strategy in the Repository, so that new data is loaded only when necessary (e.g. only when the user changes the city for which a forecast is being displayed and/or when the cached forecast data has become stale, based on a timestamp).  You should include log statements to demonstrate when your app is fetching new data and when it is relying on cached data.

  * Move the `AsyncTask` itself to a separate class (outside the main activity class), and make any modifications needed to the `AsyncTask` to ensure that it can operate separately.  Since the `AsyncTask` will no longer be able to access UI components within the main activity class, you'll likely need to provide a callback function that will be called in `onPostExecute()` to pass the forecast data off to another location in the application. as `LiveData`, so it can be observed.

  * Implement a `ViewModel` class to serve as the intermediary between the Repository class and the UI.  This class should contain methods for triggering a new data load and for returning the forecast data to the UI.

  * Set up the UI (i.e. the main activity class) to observe changes to the forecast data held behind the `ViewModel` and to update the state of the UI as appropriate based on changes to that data.  Importantly, this should be done in such a way that the progress bar and error message behave as currently implemented in the UI.

As a result of these changes, you should see your app fetch results from the OpenWeatherMap API only one time through typical usage of the app, including through rotations of the phone and navigation around the app.

## 2. Add some basic user preferences to the app

When you run the version of the app provided in this repository, you'll probably notice a settings icon in the title bar of the main activity.  Your second task in this assignment is to create a new activity named `SettingsActivity` that implements a user preferences screen using a `PreferenceFragment`.  This activity should be launched when you click the settings icon in the main activity.

The preferences screen should allow the user to set the following preferences:

  * **Weather units** - The user should be allowed to select between "Imperial", "Metric", and "Kelvin" temperature units.  The currently-selected value should be displayed as the summary for the preference.  See the OpenWeatherMap API documentation here for more info on how this preference value will be used to formulate API requests: https://openweathermap.org/forecast5#data.

  * **Weather location** - The user should be allowed to enter an arbitrary location for which to fetch a forecast.  The currently-set value should be set as the summary for the preference.  You can specify any default location you'd like.  See the OpenWeatherMap API documentation here for more info on how this preference value will be used to formulate API requests: https://openweathermap.org/forecast5#name5.

The settings of these preferences should affect the URL used to query the OpenWeatherMap API.  The app should be hooked up so that any change to the preferences results in the OpenWeatherMap API being re-queried and the new results being displayed.  Importantly, there are a couple places in the UI and elsewhere that will also need to be updated in response to a change in preferences:
  * The weather location displayed at the top of the main activity.
  * The units displayed in the main activity's forecast list and in the forecast item detail activity.
  * The location displayed in the map when the corresponding action bar action is triggered from the main activity.
  * The currently set forecast location in the text shared by the forecast item detail activity's share action.

All of these values are currently taken from the class `WeatherPreferences`.

## Submission

As usual, we'll be using GitHub Classroom for this assignment, and you will submit your assignment via GitHub. Make sure your completed files are committed and pushed by the assignment's deadline to the master branch of the GitHub repo that was created for you by GitHub Classroom. A good way to check whether your files are safely submitted is to look at the master branch your assignment repo on the github.com website (i.e. https://github.com/osu-cs492-w20/assignment-3-YourGitHubUsername/). If your changes show up there, you can consider your files submitted.

## Grading criteria

This assignment is worth 100 points, broken down as follows:

  * 60 points: Implements `ViewModel` architecture
    * 20 points: implements Repository class to perform data fetching and store data.
    * 10 points: implements `ViewModel` class to interface between UI and Repository
    * 15 points: observes `ViewModel` data in UI and updates the UI state appropriately (including progress bar and error message) as data changes
    * 10 points: data is cached in Repository, and cached data is used when appropriate instead of fetching new data
    * 5 points: adds logging statements to demonstrate when cached data is being used and when data is being fetched

  * 40 points: Implements user settings activity
    * 15 points: implements a preference fragment to allow the user to select temperature units and forecast location
    * 5 points: summaries of both preferences reflect the current values set for those preferences
    * 20 points: changing preference values results in new data being fetched/displayed and correct updates being made to the UI, as described above
