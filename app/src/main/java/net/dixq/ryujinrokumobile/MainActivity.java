package net.dixq.ryujinrokumobile;

import android.app.NativeActivity;
import android.util.Log;

import net.dixq.ryujinrokumobile.dxlib.Dx;

public class MainActivity extends NativeActivity {
    public void callback(){
        Log.e("rm","callback");
        Dx.INSTANCE.DxLibInit();
    }
}
