package com.example.sendit;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.telephony.SmsManager;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;
public class MainActivity extends AppCompatActivity {
   EditText phonenumber , message ;
    Button send;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        send=findViewById(R.id.SendOne);
        phonenumber=findViewById(R.id.numberkey);
        message=findViewById(R.id.Edittext1);
        send.setOnClickListener(view -> {
            String number=phonenumber.getText().toString();
            String msg=message.getText().toString();
           {
                try {
                    SmsManager smsManager = SmsManager.getDefault();
                    smsManager.sendTextMessage(number, null, msg, null, null);
                    Toast.makeText(this, "Message Sent", Toast.LENGTH_LONG).show();
                } catch (Exception e) {
                    Toast.makeText(this, "Details incorrect or some info is missing", Toast.LENGTH_LONG).show();
                }

            }
        });

    }
}