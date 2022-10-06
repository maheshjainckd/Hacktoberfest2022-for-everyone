// package can vary 

import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.ImageView
import android.widget.TextView
import androidx.recyclerview.widget.RecyclerView

class FoodAdapter(private val foodList: ArrayList<FoodData>):RecyclerView.Adapter<FoodAdapter.FoodViewHolder>() {

    var onItemClick: ((FoodData) -> Unit)? =  null

    class FoodViewHolder(itemView: View): RecyclerView.ViewHolder(itemView) {
        val foodImage: ImageView = itemView.findViewById(R.id.foodImage)
        val foodName: TextView = itemView.findViewById(R.id.foodName)
    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): FoodViewHolder {
        val view = LayoutInflater.from(parent.context).inflate(R.layout.item_layout, parent, false)
        return FoodViewHolder(view)
    }

    override fun onBindViewHolder(holder: FoodViewHolder, position: Int) {
        val food = foodList[position]
        holder.foodImage.setImageResource(food.image)
        holder.foodName.text = food.name

        holder.itemView.setOnClickListener {
            onItemClick?.invoke(food)
        }
    }

    override fun getItemCount(): Int {
        return foodList.size
    }
}