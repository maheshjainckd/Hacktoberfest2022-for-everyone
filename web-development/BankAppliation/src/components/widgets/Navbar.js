import React from 'react'
import { Link } from 'react-router-dom'
import "../../styles/Navbar.css"

function Navbar() {
    return (

        <div className="bar">



            <Link className="logo-link" to="/home"  >
                <div className="logo">
                    <h1>AMBNOX</h1>
                </div>
            </Link>



        </div>

    )
}

export default Navbar
