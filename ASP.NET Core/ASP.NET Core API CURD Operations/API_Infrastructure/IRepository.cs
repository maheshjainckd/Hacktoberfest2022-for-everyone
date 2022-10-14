using System.Collections.Generic;
using System.Threading.Tasks;
using SimpelAPI.Model;

namespace SimpelAPI.API_Infrastructure
{
    public interface IRepository
    {
        Task<List<Product>> GetAllProductsAsync();

        Task<Product> GetProductAsync(int? ID);

        Task AddProductAsync(Product product);

        Task UpdateProductAsync(Product product);

        Task DeleteProductAsync(int? ID);

    }
}