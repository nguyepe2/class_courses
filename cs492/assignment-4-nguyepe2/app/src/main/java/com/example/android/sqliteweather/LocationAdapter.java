package com.example.android.sqliteweather;

import android.content.Context;
import android.content.SharedPreferences;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.preference.PreferenceManager;
import androidx.recyclerview.widget.RecyclerView;

import com.example.android.sqliteweather.data.LocationHolder;

import java.util.ArrayList;
import java.util.List;

public class LocationAdapter extends RecyclerView.Adapter<LocationAdapter.LocationItemViewHolder> {

    private List<LocationHolder> mLocationItems;
    private OnLocationItemClickListener mLocationItemClickListener;

    public interface OnLocationItemClickListener {
        void onLocationItemClick(LocationHolder locationHolder);
    }

    public LocationAdapter(OnLocationItemClickListener clickListener) {
        mLocationItems = new ArrayList<>();
        mLocationItemClickListener = clickListener;
    }

    public void updateLocationItems(List<LocationHolder> locationHolders) {
        mLocationItems = locationHolders;
        notifyDataSetChanged();
    }

    @Override
    public int getItemCount() {
        if (mLocationItems != null) {
            return mLocationItems.size();
        } else {
            return 0;
        }
    }

    @Override
    public LocationItemViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        LayoutInflater inflater = LayoutInflater.from(parent.getContext());
        View itemView = inflater.inflate(R.layout.activity_location_details, parent, false); //change forecast_list_item
        return new LocationItemViewHolder(itemView);
    }

    @Override
    public void onBindViewHolder(@NonNull LocationItemViewHolder holder, int position) {
        holder.bind(mLocationItems.get(position));
    }

    class LocationItemViewHolder extends RecyclerView.ViewHolder implements View.OnClickListener{
        private TextView mLocation_name;
        private TextView mForecastTempDescriptionTV;
        private ImageView mWeatherIconIV;

        public LocationItemViewHolder(View itemView) {
            super(itemView);
            mLocation_name = itemView.findViewById(R.id.location_name);
            itemView.setOnClickListener(this);
        //    mForecastTempDescriptionTV = itemView.findViewById(R.id.tv_forecast_temp_description);
        //    mWeatherIconIV = itemView.findViewById(R.id.iv_weather_icon);
          //  itemView.setOnClickListener(this);
        }

        public void bind(LocationHolder locationHolder) {
            //Context context = mLocation_name.getContext();
            //SharedPreferences sharedPreferences = PreferenceManager.getDefaultSharedPreferences(context);
            /*String location = sharedPreferences.getString(
                    context.getString(R.string.pref_location_key),
                    context.getString(R.string.pref_location_default_value)
            );*/


         mLocation_name.setText(locationHolder.location);
        }

        @Override
        public void onClick(View v) {
            LocationHolder locationHolder = mLocationItems.get(getAdapterPosition());
            mLocationItemClickListener.onLocationItemClick(locationHolder);
        }
    }
}

