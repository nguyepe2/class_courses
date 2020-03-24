package com.example.android.connectedweather;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.TextView;

import com.example.android.connectedweather.data.storeForecast;

public class weatherdetailActivity extends AppCompatActivity {
    private static final String TAG = weatherdetailActivity.class.getSimpleName();



    public static final String EXTRA_WEATHER_INFO = "storeForecast";
    private storeForecast moreInfo;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_weatherdetail);

        Log.d(TAG, "before Intent intent");

        Intent intent = getIntent();
        if (intent != null && intent.hasExtra(EXTRA_WEATHER_INFO)) {
            moreInfo = (storeForecast)intent.getSerializableExtra(EXTRA_WEATHER_INFO);

            Log.d(TAG, "after intent.getSerializableExtra");


            TextView feelsLike = findViewById(R.id.tv_feels_like);
            feelsLike.setText("It feels like: " + Double.toString((Math.round(moreInfo.main.feels_like - 273)*100.00)/100.00) + "C ");

            TextView minTemp = findViewById(R.id.tv_temp_min);
            minTemp.setText("The minimum temperature is: " + Double.toString((Math.round(moreInfo.main.temp_min - 273)*100.00)/100.00) + "C ");

            TextView maxTemp = findViewById(R.id.tv_temp_max);
            maxTemp.setText("The maximum temperature is: " + Double.toString((Math.round(moreInfo.main.temp_max - 273)*100.00)/100.00) + "C ");
        }
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.weather_detail, menu);
        return true;
    }

    public void viewMap() {
        if (moreInfo != null) {
            Uri geoLocation = Uri.parse("geo:44.5646,123.2620");
            Intent intent = new Intent(Intent.ACTION_VIEW, geoLocation);

            PackageManager packageManager = getPackageManager();
            packageManager.queryIntentActivities(intent, PackageManager.MATCH_DEFAULT_ONLY);

            intent.setPackage("com.google.android.apps.maps");
            if (intent.resolveActivity(getPackageManager()) != null) {
                startActivity(intent);
            }
        }
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.action_view_map:
                viewMap();
                return true;
            case R.id.action_share:
                shareWeather();
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }

    public void shareWeather() {
        if (moreInfo != null) {
            String shareText = (
                    "It feels like: " + Double.toString((Math.round(moreInfo.main.feels_like - 273)*100.00)/100.00) + "C "
            + "The minimum temperature is: " + Double.toString((Math.round(moreInfo.main.temp_min - 273)*100.00)/100.00) + "C "
            + "The maximum temperature is: " + Double.toString((Math.round(moreInfo.main.temp_max - 273)*100.00)/100.00) + "C ");
            Intent shareIntent = new Intent(Intent.ACTION_SEND);
            shareIntent.putExtra(Intent.EXTRA_TEXT, shareText);
            shareIntent.setType("text/plain");

            Intent chooserIntent = Intent.createChooser(shareIntent, null);
            startActivity(chooserIntent);
        }
    }
}
