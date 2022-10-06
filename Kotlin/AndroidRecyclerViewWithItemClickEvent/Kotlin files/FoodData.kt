// package can vary

import android.os.Parcel
import android.os.Parcelable

data class FoodData(val image: Int, val name: String): Parcelable {
    constructor(parcel: Parcel) : this(
        parcel.readInt(),
        parcel.readString()!!
    ) {
    }

    override fun writeToParcel(parcel: Parcel, flags: Int) {
        parcel.writeInt(image)
        parcel.writeString(name)
    }

    override fun describeContents(): Int {
        return 0
    }

    companion object CREATOR : Parcelable.Creator<FoodData> {
        override fun createFromParcel(parcel: Parcel): FoodData {
            return FoodData(parcel)
        }

        override fun newArray(size: Int): Array<FoodData?> {
            return arrayOfNulls(size)
        }
    }
}
