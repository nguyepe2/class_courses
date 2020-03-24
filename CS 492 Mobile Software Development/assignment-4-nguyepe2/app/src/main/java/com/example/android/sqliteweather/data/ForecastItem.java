package com.example.android.sqliteweather.data;

import java.io.Serializable;
import java.util.Date;

/*
 * This is the class that's used to represent an individual forecast item throughout the app.
 */
public class ForecastItem implements Serializable {
    public Date dateTime;
    public String description;
    public String icon;
    public long temperature;
    public long temperatureLow;
    public long temperatureHigh;
    public long humidity;
    public long windSpeed;
    public String windDirection;
}
