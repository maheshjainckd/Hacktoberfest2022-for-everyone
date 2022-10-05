import React from 'react';
import { GlobalContext } from '../context';
import TodoCard from '../components/TodoCard';


const Home = () => {
    const { data } = GlobalContext();
    return (
        <div className='container mt-3 mb-3'>
            <div className="row row-colos-1 row-cols-md-2 g-4">
                {data.map(todo => {
                    return (
                        <div className="col" key={todo.id}>
                            <TodoCard todo={todo} />
                        </div>
                    )
                })}
            </div>
        </div>
    );
};

export default Home;