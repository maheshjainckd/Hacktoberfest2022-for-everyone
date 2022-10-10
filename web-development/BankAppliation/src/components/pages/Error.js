import React from 'react'
import "../../styles/Error.css"
import bhau from "../../images/bhau.png"
function Error() {
    return (
        <div className="error">
            BHIYA JI GALAT PATH KHOL DIYE AAP <br/>
            404 ERROR <br/>
            PAGE NOT FOUND <br/>
            <img src={bhau}/>
        </div>
    )
}

export default Error
