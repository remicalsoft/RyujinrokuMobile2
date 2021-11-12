package net.dixq.ryujinrokumobile

class Util {

    companion object {

        /**
         * @brief 0~valまでの乱数を返す
         */
        fun randf(value: Float): Float {
            return (Math.random() * value).toFloat()
        }

        /**
         * @brief -val~valまでの乱数を返す
         */
        fun randf2(value: Float): Float {
            return ((Math.random()-0.5)*2*value).toFloat()
        }

    }

}
