package com.example.wohn.mailsearcher;

import android.content.Context;
import android.content.res.AssetManager;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.text.method.ScrollingMovementMethod;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URISyntaxException;
import java.net.URL;
import java.util.HashMap;
import java.util.Map;

public class MainActivity extends AppCompatActivity {
    TextView resultView;
    EditText inputTextView;
    Button clr_btn;
//    Map<String, String> nameList;
    String[] nameList;
    String[] nameResultList;
    int nameListIndex;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
//        nameList = new HashMap<String, String>();
        nameList = new String[1000];
        nameResultList = new String[1000];
        nameListIndex = 0;
        resultView = (TextView)findViewById(R.id.ResultView);
        inputTextView = (EditText) findViewById(R.id.InputView);
        clr_btn = (Button) findViewById(R.id.clr_btn);
        clr_btn.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View view) {
                inputTextView.setText("");
            }
        });
        resultView.setMovementMethod(new ScrollingMovementMethod());
        inputTextView.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {

            }

            @Override
            public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
//                String[] list = searchDepartment(charSequence.toString());
                if (charSequence.toString().equals("")) {
                    resultView.setText("");
                } else {
                    String result = searchName(charSequence.toString());
                    resultView.setText(result);
                }
            }

            @Override
            public void afterTextChanged(Editable editable) {

            }
        });

        AssetManager am = getResources().getAssets();
//        InputStream is = null;
        try {
//            is = am.open("TotalMailList.txt");
//            URL url = getClass().getResource("/assets/TotalMailList.txt");
//            File f = new File(url.toURI());
            BufferedReader reader = new BufferedReader(new InputStreamReader(
                    am.open("TotalMailList.txt"), "utf-8"));


//            BufferedReader reader = new BufferedReader(new InputStreamReader(getAssets().open("TotalMailList.txt")));
            String line;
            while ((line = reader.readLine()) != null) {
                nameList[nameListIndex] = line;
                nameListIndex++;
//                String[] RowData = line.split(" ");
//                if (nameList.containsKey(RowData[0])) {
//                    String a = nameList.get(RowData[0]);
//                    a = a + ", " + RowData[1];
//                    nameList.put(RowData[0], a);
//                } else {
//                nameList.put(RowData[0], RowData[1])

//                }
//                date = RowData[0];
//                value = RowData[1];
                // do something with "data" and "value"
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        resultView.setText(nameList[0]);
    }

    public String searchName(String inputName) {
        String result = "";
//        boolean isFirst = false;
        nameResultList = nameList;
        int resultListIndex = nameListIndex;
//        char firstName = inputName.charAt(0);
        //리스트의 끝을 알아서 탐색의 길이를 제한해야 한다.
        for (int inputNameIndex = 0; inputNameIndex < inputName.length(); inputNameIndex++) {
            String[] sortList = new String[1000];
            int len = 0;
            if (isChosung(inputName.charAt(inputNameIndex))) {
                for (int i = 0; i < resultListIndex; i++) {
                    if (Direct(nameResultList[i].charAt(inputNameIndex)) == inputName.charAt(inputNameIndex)) {
                        sortList[len++] = nameResultList[i];
                    }
                }
            } else {
                for (int i = 0; i < resultListIndex; i++) {
                    if (nameResultList[i].equals("")) {
                        break;
                    }
                    if ((nameResultList[i].charAt(inputNameIndex)) == inputName.charAt(inputNameIndex)) {
                        sortList[len++] = nameResultList[i];
                    }
                }
            }
            nameResultList = sortList;
            resultListIndex = len;

        }

//        if(!isChosung(firstName)) {
//            for (int i = 0 ; i <= nameListIndex; i++) {
//                if (nameList[i].charAt(0) == firstName) {
//                    int soa = nameResultList.length;
//                    nameResultList[soa] = nameList[i];
//                }
//            }
//        } else {
//            for (int i = 0 ; i <= nameListIndex; i++) {
//                if (Direct(nameList[i].charAt(0)) == firstName) {
//
//                }
//            }
//        }
//
//        for(int i = 1; i < inputName.length(); i++) {
//            for(int j = 0; j < nameResultList.length; j++) {
//
//            }
//            if (nameList[i].contains(inputName)) {
//                if (!isFirst) {
//                    result = result + nameList[i];
//                    isFirst = true;
//                } else {
//                    result = result + "\n" + nameList[i];
//                }
//            }
//            if(Direct(nameList[i]).contains(inputName)) {
//                if (!isFirst) {
//                    result = result + nameList[i];
//                    isFirst = true;
//                } else {
//                    result = result + "\n" + nameList[i];
//                }
//            }
//        }
        for (int i = 0; i < resultListIndex; i++) {
            result += nameResultList[i] + "\n";
        }
        return result;
    }
    public Boolean isChosung(char c) {
        int k = c;
        if (k >= 12593 && k <= 12622) {
            return true;
        } else {
            return false;
        }
    }
    public char Direct(char name){

//        int a = name.length();
        char b = name;
        char chosung = 'ㄱ';
//        for (int i = 0; i < a; i++) {
//            char b =name.charAt(i);
            int first = ((b - 44032 ) / ( 21 * 28 ));
//            first = first - 36;
            switch(first)
            {
                case 0 :
                case 1: chosung = 'ㄱ';
                    break;
                case 2: chosung = 'ㄴ';
                    break;
                case 3:
                case 4: chosung ='ㄷ';
                    break;
                case 5: chosung ='ㄹ';
                    break;
                case 6: chosung ='ㅁ';
                    break;
                case 7:
                case 8: chosung ='ㅂ';
                    break;
                case 9:
                case 10: chosung ='ㅅ';
                    break;
                case 11: chosung ='ㅇ' ;
                    break;
                case 12:
                case 13: chosung ='ㅈ';
                    break;
                case 14: chosung ='ㅊ';
                    break;
                case 15: chosung ='ㅋ';
                    break;
                case 16: chosung ='ㅌ';
                    break;
                case 17: chosung ='ㅍ';
                    break;
                case 18: chosung ='ㅎ';
                    break;
            }
//        }
        return chosung;
//        return chosung.substring(0,3);
    }

}
