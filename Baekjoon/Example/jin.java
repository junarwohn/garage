package snu;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.Reader;
import java.io.Writer;
import java.text.DecimalFormat;
import java.util.StringTokenizer;

public class TeamAssignment {
   
              
      public static void main(String[] args) throws Exception {
    
       /*
        * 입력및 출력 배열
        */
         
      double[] sumOfYearlyPrecipitation = new double[30];
     // int [] day
      int[] numberOfYear = new int[30];
      double averageOfYearlyPrecipitation = 0;

      
      /*
       * 입력파일 열고 읽기
       */
      InputStream is = new FileInputStream("c:\\강수량.txt"); 
      Reader reader = new InputStreamReader(is);
      BufferedReader brd = new BufferedReader(reader);
      
      StringTokenizer tokens = null;
      String readLine1 = null;
      
    //파일의 처음부터 끝까지 한줄씩 읽는다. 
      while (true){
         readLine1 = null;
         readLine1 = brd.readLine();
         if( readLine1 == null ) { 
            break;
         }
         //읽은 문자열을 토큰으로 분해한다. 
         tokens = new StringTokenizer(readLine1, "-");
         
         //임시로 데이터를 담을 변수를 정의
         int year = 0;
         int month = 0;
         int day = 0;
         double precip = 0;
      
         double sumOfPrecipitation = 0;
         //문자열을 분해하여 토큰을 하나씩 읽는다. 
         while(tokens.hasMoreElements()){

            //읽어들인 토큰을 int와 double로 변환한다. 
           	year = Integer.parseInt(tokens.nextToken());
            month = Integer.parseInt(tokens.nextToken());
            day = Integer.parseInt(tokens.nextToken());
            precip =  Double.parseDouble(tokens.nextToken());
            
            if(month==02) {
               if(day==29) {
                  continue;
                  }
                 }
   
               }
         
         //읽어들인 값을 각 배열에 넣는다. 
         sumOfYearlyPrecipitation[year-1988] =sumOfYearlyPrecipitation[year-1988]+precip;
         
         
         for(int i=0; i<31; i++) {
           /*  sumOfYearlyPrecipitation[i] = sumOfYearlyPrecipitation[i]+precip;
            sumOfPrecipitation += sumOfYearlyPrecipitation[i];
            averageOfYearlyPrecipitation= sumOfPrecipitation/numberOfYear.length;
          */
            System.out.println(sumOfYearlyPrecipitation[i]);
         }
      

        
         

      brd.close();
     }
      
}