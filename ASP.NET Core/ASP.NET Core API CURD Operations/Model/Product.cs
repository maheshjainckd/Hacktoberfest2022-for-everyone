using System;
using System.Collections.Generic;

#nullable disable

namespace SimpelAPI.Model
{
    public partial class Product
    {
        public int Id { get; set; }
        public string ProductName { get; set; }
        public int? Price { get; set; }
        public int? Quantity { get; set; }
    }
}
