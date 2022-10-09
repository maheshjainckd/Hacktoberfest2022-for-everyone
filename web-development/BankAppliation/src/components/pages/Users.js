import React, { useState, useEffect } from 'react'
import { Link , Redirect} from 'react-router-dom'
import { db } from "../../Firebase"
import "../../styles/Users.css"
function Users({ authorize }) {
    const [users, setusers] = useState([])
    
    useEffect(() => {
        db.collection('customers').onSnapshot(snapshot => {

            setusers(snapshot.docs.map(doc => (doc.data())))

        })

    }, [])
    if (!authorize) {
        return <Redirect to="/" />
    }
    else {
        return (
            <div className="users">
                <h1 className="history-header">CUSTOMERS</h1>
                <table className="tbl table" >
                    <tbody>
                        <tr>
                            <th>Name</th>
                            <th>number</th>
                            <th>Email</th>
                            <th>Account</th>
                            <th>Amount</th>
                            <th>Transact</th>
                        </tr>
                        {users.map((item) => {


                            return (<tr key={item.account}>
                                <td>{item.name}</td>
                                <td>{item.number}</td>
                                <td>{item.email}</td>
                                <td>{item.account}</td>
                                <td>{item.amount}</td>
                                <td><Link to={{
                                    pathname: `/home/users/${item.name}`, state: {
                                        name: item.name,
                                        account: item.amount
                                    }
                                }}><button className="btnnn btn-success">Transfer</button></Link></td>
                            </tr>)


                        })}
                    </tbody>
                </table>


            </div>
        )
    }

}

export default Users
