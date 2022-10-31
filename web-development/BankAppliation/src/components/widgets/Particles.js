import React from 'react'

import BigBangStarField from 'react-big-bang-star-field'

function Particles() {
    return (
        <BigBangStarField
            numStars={160}
            maxStarSpeed={1}
            scale={5}
            style={{
                position: 'absolute',
                width: '100%',
                height: '100%'
            }}
            starColor={"233, 233, 233"}
        />
    )
}


export default Particles