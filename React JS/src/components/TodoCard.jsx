import React from 'react';
import {useNavigate } from 'react-router-dom'

const TodoCard = ({ todo }) => {
    const navigate = useNavigate()
    const cardHendler = (e) => {
        navigate(`/detail-todo/${todo.id}`)
    }
    return (
        <div className='card card-todo' onClick={cardHendler} key={todo.id}>
            <div className="card-body">
                <h3 className="card-title">{todo.title}</h3>
                {todo.body.length < 80
                    ? <p className="card-text">{todo.body}</p>
                    : <p className="card-text">{todo.body.slice(0,80)}) <small className="fw-lighter">... click to see more</small></p>
                }
                <div className="d-flex justify-content-between align-items-center">
                    <input type="checkbox" name="done" id="done" className='form-check-input' defaultChecked={todo.done} />
                    <label htmlFor="done" className='form-check-label mx-2'>done !</label>
                </div>
            </div>
        </div>
    );
};

export default TodoCard;