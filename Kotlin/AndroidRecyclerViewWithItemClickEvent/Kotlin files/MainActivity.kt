// package can vary

import android.content.Intent
import android.graphics.Color
import android.graphics.drawable.ColorDrawable
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.recyclerview.widget.LinearLayoutManager
import androidx.recyclerview.widget.RecyclerView

class MainActivity : AppCompatActivity() {

    private lateinit var recyclerView: RecyclerView
    private lateinit var foodList: ArrayList<FoodData>
    private lateinit var foodAdapter: FoodAdapter
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        supportActionBar!!.setBackgroundDrawable(ColorDrawable(Color.parseColor("#FF3700B3")))

        recyclerView = findViewById(R.id.recylerview)
        recyclerView.setHasFixedSize(true)
        recyclerView.layoutManager = LinearLayoutManager(this)

        foodList = ArrayList()

        // add the images you want to use in you project to the drawable and then use here
        foodList.add(FoodData(R.drawable.chicken_curry, "Chicken Curry"))
        foodList.add(FoodData(R.drawable.cauliflower_potato_and_pea_curry, "Cauliflower potato and pea curry"))
        foodList.add(FoodData(R.drawable.chicken_tikka_masala, "Chicken tikka masala"))
        foodList.add(FoodData(R.drawable.homemade_naan, "Homemade Naan"))
        foodList.add(FoodData(R.drawable.cricket_pot_butter_chicken, "Cricket pot butter chicken"))
        foodList.add(FoodData(R.drawable.creamy_cashew_indian_butter_paneer, "Indian butter paneer"))
        foodList.add(FoodData(R.drawable.indian_butter_chicken, "Indian butter chicken"))
        foodList.add(FoodData(R.drawable.indian_cauliflower_fried_rice, "Indian cauliflower fried rice"))
        foodList.add(FoodData(R.drawable.indian_spiced_chickpea_flatbread, "Indian spiced chickpea flatbread"))
        foodList.add(FoodData(R.drawable.insta_pot_butter_chicken, "Insta pot butter chicken"))
        foodList.add(FoodData(R.drawable.lamb_curry, "CLamb curry"))
        foodList.add(FoodData(R.drawable.slow_kooker_chicken_tikka_masala, "slow cooker chicken tikka masala"))
        foodList.add(FoodData(R.drawable.tandoori_chicken, "Tandoori chicken"))
        foodList.add(FoodData(R.drawable.tandoori_chicken_drumsticks, "Tandoori chicken drumsticks"))
        foodList.add(FoodData(R.drawable.thirty_minute_chicken_biriyani, "Thirty minute chicken biriyani"))
        foodList.add(FoodData(R.drawable.instant_pot_indian_butter_shrimp, "insta pot indian butter shrimp"))

        foodAdapter = FoodAdapter(foodList)
        recyclerView.adapter = foodAdapter

        foodAdapter.onItemClick = {
            val intent = Intent(this, DetailedActivity::class.java)
            intent.putExtra("food", it)
            startActivity(intent)
        }
    }
}