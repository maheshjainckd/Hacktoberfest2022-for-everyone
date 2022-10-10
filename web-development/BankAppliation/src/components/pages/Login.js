import React, { useState, useEffect } from 'react'
import { Redirect, useHistory } from "react-router-dom"
import "../../styles/Login.css"
import Particles from '../widgets/Particles';
import { db } from "../../Firebase"
function Login({ authorize, setauthorize }) {
    let history = useHistory();
    const [username, setusername] = useState('')
    const [password, setpassword] = useState('')

    function submitHandler(e) {
        e.preventDefault()

        if (username !== "" && password !== "") {
            if (username === "earthboxer" && password === "earthboxer") {
                history.push("/home")
                setauthorize(true)

            }
            else {
                alert("not authorized personell")
                setpassword("")
                setusername("")
            }
        }
        else {
            alert("all fields are complusory")
        }


    }
    if (authorize === false) {
        return (
            <div className="login-container">
                <Particles className="particles" />
                <h1 className="login-heading">WELCOME TO AMBNOX BANKING </h1>
                <form className="login-form" onSubmit={submitHandler}>
                    <h4>Username</h4>
                    <input type="text" value={username} onChange={(e) => { setusername(e.target.value) }} />
                    <h4>password</h4>
                    <input type="password" value={password} onChange={(e) => { setpassword(e.target.value) }} />
                    <br />
                    <button type="submit">LOGIN</button>
                </form>

            </div>
        )
    }
    else {
        return <Redirect to="/home" />
    }

}

export default Login
