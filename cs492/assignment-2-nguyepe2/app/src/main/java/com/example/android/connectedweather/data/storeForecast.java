package com.example.android.connectedweather.data;

import java.io.Serializable;
import java.util.ArrayList;


public class storeForecast implements Serializable {
    public String dt_txt;
    public mainInfo main;
    public ArrayList<OpenWeather> weather;

}
