package com.example.android.sqliteweather.utils;

import android.content.Context;
import android.net.Uri;

import com.example.android.sqliteweather.R;
import com.example.android.sqliteweather.data.ForecastItem;
import com.google.gson.Gson;

import java.io.Serializable;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.TimeZone;

public class OpenWeatherMapUtils {

    public static final String EXTRA_FORECAST_ITEM = "com.example.android.sqliteweather.utils.ForecastItem";

    private final static String OWM_FORECAST_BASE_URL = "https://api.openweathermap.org/data/2.5/forecast";
    private final static String OWM_ICON_URL_FORMAT_STR = "https://openweathermap.org/img/w/%s.png";
    private final static String OWM_FORECAST_QUERY_PARAM = "q";
    private final static String OWM_FORECAST_UNITS_PARAM = "units";
    private final static String OWM_FORECAST_APPID_PARAM = "appid";
    private final static String OWM_FORECAST_DATE_FORMAT = "yyyy-MM-dd HH:mm:ss";
    private final static String OWM_FORECAST_TIME_ZONE = "UTC";

    /*
     * Set your own APPID here.
     */
    private final static String OWM_FORECAST_APPID = "cbc8fb0a4cfc7b006d06aea3515ee4d5";


    /*
     * The below several classes are used only for JSON parsing with Gson.  The main class that's
     * used to represent a single forecast item throughout the rest of the app is the ForecastItem
     * class in the data package.
     */
    static class OWMForecastResults {
        OWMForecastListItem[] list;
    }

    static class OWMForecastListItem {
        String dt_txt;
        OWMForecastItemMain main;
        OWMForecastItemWeather[] weather;
        OWMForecastItemWind wind;
    }

    static class OWMForecastItemMain {
        float temp;
        float temp_min;
        float temp_max;
        float humidity;
    }

    static class OWMForecastItemWeather {
        String description;
        String icon;
    }

    static class OWMForecastItemWind {
        float speed;
        float deg;
    }

    public static String buildForecastURL(String forecastLocation, String temperatureUnits) {
        return Uri.parse(OWM_FORECAST_BASE_URL).buildUpon()
                .appendQueryParameter(OWM_FORECAST_QUERY_PARAM, forecastLocation)
                .appendQueryParameter(OWM_FORECAST_UNITS_PARAM, temperatureUnits)
                .appendQueryParameter(OWM_FORECAST_APPID_PARAM, OWM_FORECAST_APPID)
                .build()
                .toString();
    }

    public static String buildIconURL(String icon) {
        return String.format(OWM_ICON_URL_FORMAT_STR, icon);
    }

    public static ArrayList<ForecastItem> parseForecastJSON(String forecastJSON) {
        Gson gson = new Gson();
        OWMForecastResults results = gson.fromJson(forecastJSON, OWMForecastResults.class);
        if (results != null && results.list != null) {
            ArrayList<ForecastItem> forecastItems = new ArrayList<>();
            SimpleDateFormat dateParser = new SimpleDateFormat(OWM_FORECAST_DATE_FORMAT);
            dateParser.setTimeZone(TimeZone.getTimeZone(OWM_FORECAST_TIME_ZONE));

            /*
             * Loop through all results parsed from JSON and condense each one into one
             * single-level ForecastItem object.
             */
            for (OWMForecastListItem listItem : results.list) {
                ForecastItem forecastItem = new ForecastItem();

                try {
                    forecastItem.dateTime = dateParser.parse(listItem.dt_txt);
                } catch (ParseException e) {
                    e.printStackTrace();
                    forecastItem.dateTime = null;
                }

                forecastItem.description = listItem.weather[0].description;
                forecastItem.icon = listItem.weather[0].icon;

                forecastItem.temperature = Math.round(listItem.main.temp);
                forecastItem.temperatureHigh = Math.round(listItem.main.temp_max);
                forecastItem.temperatureLow = Math.round(listItem.main.temp_min);
                forecastItem.humidity = Math.round(listItem.main.humidity);

                forecastItem.windSpeed = Math.round(listItem.wind.speed);
                forecastItem.windDirection = windAngleToDirection(listItem.wind.deg);

                forecastItems.add(forecastItem);
            }

            return forecastItems;
        } else {
            return null;
        }
    }

    public static String windAngleToDirection(double angleDegrees) {
        if (angleDegrees >= 0 && angleDegrees < 11.25) {
            return "N";
        } else if (angleDegrees >= 11.25 && angleDegrees < 33.75) {
            return "NNE";
        } else if (angleDegrees >= 33.75 && angleDegrees < 56.25) {
            return "NE";
        } else if (angleDegrees >= 56.25 && angleDegrees < 78.75) {
            return "ENE";
        } else if (angleDegrees >= 78.75 && angleDegrees < 101.25) {
            return "E";
        } else if (angleDegrees >= 101.25 && angleDegrees < 123.75) {
            return "ESE";
        } else if (angleDegrees >= 123.75 && angleDegrees < 146.25) {
            return "SE";
        } else if (angleDegrees >= 146.25 && angleDegrees < 168.75) {
            return "SSE";
        } else if (angleDegrees >= 168.75 && angleDegrees < 191.25) {
            return "S";
        } else if (angleDegrees >= 191.25 && angleDegrees < 213.75) {
            return "SSW";
        } else if (angleDegrees >= 213.75 && angleDegrees < 236.25) {
            return "SW";
        } else if (angleDegrees >= 236.25 && angleDegrees < 258.75) {
            return "WSW";
        } else if (angleDegrees >= 258.75 && angleDegrees < 281.25) {
            return "W";
        } else if (angleDegrees >= 281.25 && angleDegrees < 303.75) {
            return "WNW";
        } else if (angleDegrees >= 303.75 && angleDegrees < 326.25) {
            return "WNW";
        } else if (angleDegrees >= 326.25 && angleDegrees < 348.75) {
            return "NNW";
        } else {
            return "N";
        }
    }

    public static String getTemperatureUnitsAbbr(Context context, String temperatureUnitsValue) {
        if (temperatureUnitsValue.equals(context.getString(R.string.pref_units_kelvin_value))) {
            return context.getString(R.string.units_kelvin);
        } else if (temperatureUnitsValue.equals(context.getString(R.string.pref_units_metric_value))) {
            return context.getString(R.string.units_metric);
        } else {
            return context.getString(R.string.units_imperial);
        }
    }
}
