package com.example.joonowohn.mailrecognizer;

import android.content.res.AssetManager;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Matrix;
import android.graphics.SurfaceTexture;
import android.hardware.Camera;
import android.hardware.camera2.CameraDevice;
import android.media.MediaRecorder;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.TextureView;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.googlecode.tesseract.android.TessBaseAPI;

import org.w3c.dom.Text;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.List;

public class MainActivity extends AppCompatActivity implements TextureView.SurfaceTextureListener {
    Bitmap image;
    private TessBaseAPI mTess;
    String datapath = "";

    private Camera mCamera;
    private Button mStart;
    private TextureView mTextureView;
    ImageView bitImg;
    Button btn;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mTextureView = (TextureView)findViewById(R.id.textureView);
        mTextureView.setSurfaceTextureListener(this);
        mTextureView.setRotation(90);
        bitImg = (ImageView)findViewById(R.id.bitmapPreview);
        btn  = (Button) findViewById(R.id.btn_scan);
        btn.setOnClickListener(new Button.OnClickListener() {
            @Override
            public void onClick(View view) {
                Bitmap bm = getBitmap();
                processImage(bm);
            }
        });

//        image = BitmapFactory.decodeResource(getResources(),R.drawable.test1);
        datapath = getFilesDir() + "/tesseract/";

        checkFile(new File(datapath + "tessdata/"));

        String lang = "kor";
        mTess = new TessBaseAPI();
        mTess.init(datapath, lang);

//        출처: http://mainia.tistory.com/4943 [녹두장군 - 상상을 현실로]
    }

    private void copyFiles() {
        try {
            String filepath = datapath + "/tessdata/kor.traineddata";

            AssetManager assetManager = getAssets();
            InputStream inStream = assetManager.open("tessdata/kor.traineddata");
            OutputStream outstream = new FileOutputStream(filepath);

            byte[] buffer = new byte[1024];
            int read;
            while((read = inStream.read(buffer)) != -1) {
                outstream.write(buffer, 0, read);
            }
            outstream.flush();
            outstream.close();
            inStream.close();

        } catch (FileNotFoundException e) {

        } catch (IOException e) {
            e.printStackTrace();
        }
    }
    private void checkFile(File dir) {
        //directory does not exist, but we can successfully create it
        if (!dir.exists()&& dir.mkdirs()){
            copyFiles();
        }
        //The directory exists, but there is no data file in it
        if(dir.exists()) {
            String datafilepath = datapath+ "/tessdata/kor.traineddata";
            File datafile = new File(datafilepath);
            if (!datafile.exists()) {
                copyFiles();
            }
        }
    }
    public void processImage(Bitmap bm) {
        String OCRresult = null;
        mTess.setImage(bm);
        OCRresult = mTess.getUTF8Text();
        TextView OCRTextView = (TextView) findViewById(R.id.textView);


        OCRTextView.setText(OCRresult);
    }






//    private void init(){
//
//        mCamera = Camera.open();
//        mCamera.setDisplayOrientation(90);
//
//        // surfaceview setting
//        mCameraHolder = mCameraView.getHolder();
//        mCameraHolder.addCallback(this);
//        mCameraHolder.setType(SurfaceHolder.SURFACE_TYPE_PUSH_BUFFERS);
//    }




    @Override
    public void onSurfaceTextureAvailable(SurfaceTexture surfaceTexture, int i, int i1) {
        mCamera = Camera.open();
        try {
            mCamera.setPreviewTexture(surfaceTexture);
            mCamera.startPreview();
        } catch (IOException e) {
            e.printStackTrace();
        }
        Camera.Parameters params = mCamera.getParameters();
        params.setFocusMode(Camera.Parameters.FOCUS_MODE_CONTINUOUS_PICTURE);
        mCamera.setParameters(params);
    }

    @Override
    public void onSurfaceTextureSizeChanged(SurfaceTexture surfaceTexture, int i, int i1) {

    }

    @Override
    public boolean onSurfaceTextureDestroyed(SurfaceTexture surfaceTexture) {
        mCamera.stopPreview();
        mCamera.release();
        return false;    }

    @Override
    public void onSurfaceTextureUpdated(SurfaceTexture surfaceTexture) {

    }
    public void autoFocus() {
        mCamera.autoFocus(new Camera.AutoFocusCallback() {
            @Override
            public void onAutoFocus(boolean b, Camera camera) {

            }
        });
    }
    public Bitmap getBitmap() {
        Bitmap bitmap = mTextureView.getBitmap();

        bitmap = RotateBitmap(bitmap, 90);

        bitmap = cropCenterBitmap(bitmap, 200, 80);
//        bitmap.getWidth();
//        bitmap.getHeight();
        bitImg.setImageBitmap(bitmap);
        return bitmap;
    }
    public static Bitmap RotateBitmap(Bitmap source, float angle)
    {
        Matrix matrix = new Matrix();
        matrix.postRotate(angle);
        return Bitmap.createBitmap(source, 0, 0, source.getWidth(), source.getHeight(), matrix, true);
    }
    public static Bitmap cropCenterBitmap(Bitmap src, int w, int h) {
        if(src == null)
            return null;

        int width = src.getWidth();
        int height = src.getHeight();

        if(width < w && height < h)
            return src;

        int x = 0;
        int y = 0;

        if(width > w)
            x = (width - w)/2;

        if(height > h)
            y = (height - h)/2;

        int cw = w; // crop width
        int ch = h; // crop height

        if(w > width)
            cw = width;

        if(h > height)
            ch = height;

        return Bitmap.createBitmap(src, x, y, cw, ch);
    }
}
