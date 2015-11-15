package sjbv.ifsp.edu.br.animacaobola;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.view.View;

/**
 * Created by Fábio on 27/03/2015.
 */



public class AnimacaoView extends View {

    private Paint paint = new Paint();

    public AnimacaoView(Context context) {
        super(context);
    }


    @Override
    protected void onDraw(Canvas canvas) {
        super.onDraw(canvas);
        canvas.drawCircle(100,100,50,paint);
    }
}
