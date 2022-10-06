// package can vary

import android.graphics.Color
import android.graphics.drawable.ColorDrawable
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.ImageView
import android.widget.TextView

class DetailedActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_detailed)

        supportActionBar!!.setBackgroundDrawable(ColorDrawable(Color.parseColor("#FF3700B3")))

        val food = intent.getParcelableExtra<FoodData>("food")
        if(food != null) {
            val textView: TextView = findViewById(R.id.detailedPageTv)
            val imageView: ImageView = findViewById(R.id.detailedPageIv)

            textView.text = food.name
            imageView.setImageResource(food.image)
        }
    }
}