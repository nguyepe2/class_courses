package com.example.android.sqliteweather;

import android.content.Intent;
import android.content.SharedPreferences;
import androidx.core.app.ShareCompat;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import androidx.preference.PreferenceManager;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.ImageView;
import android.widget.TextView;

import com.bumptech.glide.Glide;
import com.example.android.sqliteweather.data.ForecastItem;
import com.example.android.sqliteweather.utils.OpenWeatherMapUtils;

import java.text.DateFormat;

public class ForecastItemDetailActivity extends AppCompatActivity {

    private TextView mDateTV;
    private TextView mTempDescriptionTV;
    private TextView mLowHighTempTV;
    private TextView mWindTV;
    private TextView mHumidityTV;
    private ImageView mWeatherIconIV;

    private ForecastItem mForecastItem;
    private String mForecastLocation;
    private String mTemperatureUnitsAbbr;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_forecast_item_detail);

        mDateTV = findViewById(R.id.tv_date);
        mTempDescriptionTV = findViewById(R.id.tv_temp_description);
        mLowHighTempTV = findViewById(R.id.tv_low_high_temp);
        mWindTV = findViewById(R.id.tv_wind);
        mHumidityTV = findViewById(R.id.tv_humidity);
        mWeatherIconIV = findViewById(R.id.iv_weather_icon);

        SharedPreferences sharedPreferences = PreferenceManager.getDefaultSharedPreferences(this);
        mForecastLocation = sharedPreferences.getString(
                getString(R.string.pref_location_key),
                getString(R.string.pref_location_default_value)
        );
        String temperatureUnitsValue = sharedPreferences.getString(
                getString(R.string.pref_units_key),
                getString(R.string.pref_units_default_value)
        );
        mTemperatureUnitsAbbr = OpenWeatherMapUtils.getTemperatureUnitsAbbr(this, temperatureUnitsValue);

        Intent intent = getIntent();
        if (intent != null && intent.hasExtra(OpenWeatherMapUtils.EXTRA_FORECAST_ITEM)) {
            mForecastItem = (ForecastItem)intent.getSerializableExtra(
                    OpenWeatherMapUtils.EXTRA_FORECAST_ITEM
            );
            fillInLayout(mForecastItem);
        }
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.forecast_item_detail, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.action_share:
                shareForecast();
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    public void shareForecast() {
        if (mForecastItem != null) {
            String dateString = DateFormat.getDateTimeInstance(DateFormat.SHORT, DateFormat.SHORT)
                    .format(mForecastItem.dateTime);
            String shareText = getString(R.string.forecast_item_share_text, mForecastLocation,
                    dateString, mForecastItem.temperature, mTemperatureUnitsAbbr,
                    mForecastItem.description);
            ShareCompat.IntentBuilder.from(this)
                    .setType("text/plain")
                    .setText(shareText)
                    .setChooserTitle(R.string.share_chooser_title)
                    .startChooser();
        }
    }

    private void fillInLayout(ForecastItem forecastItem) {
        String dateString = DateFormat.getDateTimeInstance().format(forecastItem.dateTime);
        String detailString = getString(R.string.forecast_item_details, forecastItem.temperature,
                mTemperatureUnitsAbbr, forecastItem.description);
        String lowHighTempString = getString(R.string.forecast_item_low_high_temp,
                forecastItem.temperatureLow, forecastItem.temperatureHigh,
                mTemperatureUnitsAbbr);

        String windString = getString(R.string.forecast_item_wind, forecastItem.windSpeed,
                forecastItem.windDirection);
        String humidityString = getString(R.string.forecast_item_humidity, forecastItem.humidity);

        mDateTV.setText(dateString);
        mTempDescriptionTV.setText(detailString);
        mLowHighTempTV.setText(lowHighTempString);
        mWindTV.setText(windString);
        mHumidityTV.setText(humidityString);

        String iconURL = OpenWeatherMapUtils.buildIconURL(forecastItem.icon);
        Glide.with(this).load(iconURL).into(mWeatherIconIV);
    }
}
