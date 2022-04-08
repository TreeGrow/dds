package com.luntek.chiplink.test.dds;


import static com.luntek.chiplink.microdds.DDS.startAgent;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.luntek.chiplink.test.dds.databinding.ActivityMainBinding;

import java.net.DatagramSocket;
import java.net.InetAddress;

public class MainActivity extends AppCompatActivity {

    private final static String IP = "127.0.0.1";  //IP
    private final static int PORT = 32019;         //端口号

    private DatagramSocket receiveSocket;
    private DatagramSocket sendSocket;
    private InetAddress serverAddr;




    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
        Button startAgent = binding.startAgent;
        Button startAgent2 = binding.startAgent2;
        startAgent2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                new Thread() {
                    @Override
                    public void run() {
                        startAgent("udp4", "32019", false);
                    }
                }.start();
                startAgent.setEnabled(true);
            }
        });

        startAgent.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startAgent.setEnabled(false);
                new Thread() {
                    @Override
                    public void run() {
                        startAgent("udp4", "32019", true);
                    }
                }.start();
            }
        });
        tv.setText("udp4");
    }






}