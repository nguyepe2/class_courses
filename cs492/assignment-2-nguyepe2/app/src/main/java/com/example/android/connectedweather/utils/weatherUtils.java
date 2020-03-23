package com.example.android.connectedweather.utils;

import android.net.Uri;

import java.util.ArrayList;
import com.example.android.connectedweather.data.storeForecast;
import com.google.gson.Gson;

public class weatherUtils {
    final static String WEATHER_BASE_URL ="https://api.openweathermap.org/data/2.5/forecast";
    final static String WEATHER_QUERY_PARAM = "q";
    final static String LOCATION = "Corvallis,us";
    final static String APPID = "APPID";
    final static String APPID_KEY = "cbc8fb0a4cfc7b006d06aea3515ee4d5";

    static class openWeatherObject {
        ArrayList<storeForecast> list;
    }

    public static String buildWeatherSearchURL(String q) {
        return Uri.parse(WEATHER_BASE_URL).buildUpon()
                .appendQueryParameter(WEATHER_QUERY_PARAM, LOCATION)
                .appendQueryParameter(APPID, APPID_KEY)
                .build()
                .toString();
    }

    public static ArrayList<storeForecast> parseWeather(String json) {
        Gson gson = new Gson();
        openWeatherObject results = gson.fromJson(json, openWeatherObject.class);
        if (results != null && results.list != null) {
            return results.list;
        }
        else {
            return null;
        }
    }

}
