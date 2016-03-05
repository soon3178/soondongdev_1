package net.daum.android.map.openapi.sampleapp;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.app.Activity;
import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Vibrator;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends Activity {
	
	
	////////////////////////////////////////알림창
	//알림 메니저 객체
    NotificationManager notiManager;
    //진동을 줘보자 진동객체
    Vibrator vibrator;
    //알림 식별값
    final static int MyNoti=0;
	////////////////////////////////////////알림창
	
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
     
        setContentView(R.layout.main);
        
        
        
        
        setTitle("택배정보시스템 어플");
        setContentView(R.layout.main);
        
        Button button1 = (Button)findViewById(R.id.button_start);
        button1.setOnClickListener(buttonClickListener1);
        
        
      
    }
    
    private OnClickListener buttonClickListener1 = new OnClickListener() {
        public void onClick(View v) {
			Intent intent = new Intent(MainActivity.this, DaumMapSampleActivity.class);
			startActivity(intent);
        }
    };
    
  }
