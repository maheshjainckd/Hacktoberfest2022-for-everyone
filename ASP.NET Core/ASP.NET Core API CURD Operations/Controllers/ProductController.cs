
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Logging;
using SimpelAPI.API_Infrastructure;
using SimpelAPI.Model;

namespace SimpelAPI.Controllers

{
    [ApiController]
    [Route("api/[controller]")]
    public class ProductController : ControllerBase
    {
        private readonly IRepository _productRepository;

        public ProductController(IRepository repository)
        {
            this._productRepository = repository;
        }


        [HttpGet]
        [Route("Products")]
        public async Task<IActionResult> GetAllProducts()
        {
            try
            {
                var ProductItems = await _productRepository.GetAllProductsAsync();
                if (ProductItems == null)
                {
                    return NotFound();
                }

                return Ok(ProductItems);
            }
            catch (Exception)
            {
                return BadRequest();
            }
        }

        [HttpGet]
        [Route("GetProduct")]
        public async Task<IActionResult> GetProduct(int? ID)
        {
            if (ID == null)
            {
                return BadRequest();
            }
            try
            {
                var ProductItem = await _productRepository.GetProductAsync(ID);

                if (ProductItem == null)
                {
                    return NotFound();
                }

                return Ok(ProductItem);
            }
            catch (Exception)
            {
                return BadRequest();
            }
        }

        [HttpPost]
        [Route("AddProduct")]
        public async Task<IActionResult> AddProduct([FromBody] Product model)
        {


            if (ModelState.IsValid && model != null)
            {

                await _productRepository.AddProductAsync(model);
                return Ok();

            }
            else
            {
                return BadRequest();
            }


        }

        [HttpPost]
        [Route("UpdateProduct")]
        public async Task<IActionResult> UpdateProduct([FromBody] Product model)
        {
            if (ModelState.IsValid && model != null)
            {
                await _productRepository.UpdateProductAsync(model);
                return Ok();
            }
            else
            {
                return BadRequest();
            }
        }

        [HttpGet]
        [Route("DeleteProduct")]
        public async Task<IActionResult> DeleteProduct(int? ID)
        {
            if (ID == null)
            {
                return BadRequest();
            }
            try
            {
                await _productRepository.DeleteProductAsync(ID);

                return Ok();
            }
            catch (Exception)
            {
                return BadRequest();
            }

        }


    }


}