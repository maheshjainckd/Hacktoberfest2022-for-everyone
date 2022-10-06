import React from 'react';
import TodoDetailCard from '../components/TodoDetailCard';
import { useParams } from 'react-router-dom';
import { GlobalContext } from '../context';
import UpdateForm from '../components/UpdateForm';

  
const Detail = () => {
    const { id } = useParams();
    const { data, loading, update } = GlobalContext();
    const todo = data.find(element => element.id === Number(id));
    // console.log(todo, id);
    return (
        <div className='container  '>
            {/* {loading === true? 'mzlh': 't3mr'} */}
            <TodoDetailCard todo={todo} />
            {update && <UpdateForm todo={todo} />}
        </div>
    );
};

export default Detail;