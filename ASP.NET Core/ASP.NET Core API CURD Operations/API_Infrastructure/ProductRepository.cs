using System.Collections.Generic;
using System.Threading.Tasks;
using Microsoft.EntityFrameworkCore;
using SimpelAPI.Model;
using System.Linq;

namespace SimpelAPI.API_Infrastructure
{
    public class ProductRepository : IRepository
    {
        private readonly SimpleAPI_DBContext _dBContext;

        public ProductRepository(SimpleAPI_DBContext dBContext)
        {
            this._dBContext = dBContext;

        }

        public async Task<List<Product>> GetAllProductsAsync()
        {
            return await _dBContext.Products.ToListAsync();
        }

        public async Task<Product> GetProductAsync(int? ID)
        {
            return await _dBContext.Products.FirstOrDefaultAsync(pid => pid.Id == ID);
        }

        public async Task AddProductAsync(Product product)
        {

            await _dBContext.Products.AddAsync(product);

            await _dBContext.SaveChangesAsync();




        }

        public async Task UpdateProductAsync(Product product)
        {

            var productItemUpdate = await _dBContext.Products.FirstOrDefaultAsync(Pitem => Pitem.Id == product.Id);



            productItemUpdate.ProductName = product.ProductName;
            productItemUpdate.Price = product.Price;
            productItemUpdate.Quantity = product.Quantity;
            _dBContext.Products.Update(productItemUpdate);
            await _dBContext.SaveChangesAsync();
        }

        public async Task DeleteProductAsync(int? ID)
        {
            var productItemDelete = await _dBContext.Products.FirstOrDefaultAsync(Pitem => Pitem.Id == ID);


            _dBContext.Products.Remove(productItemDelete);
            await _dBContext.SaveChangesAsync();
        }
    }




}

