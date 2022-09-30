// Zig is a systems-programming language
// More information about this (in my opinion) amazing language can be found at: https://ziglang.org/

// Create a constant variable named "std" which imports the standard library
const std = @import("std");

// Define a public function called main and return an error (left of the '!') and on the right return 'void'
pub fn main() anyerror!void {
    // First we have to get the reader/writer interface of stdout
    const stdout = std.io.getStdOut();
    // Now this function call is a bit more interesting, with 'try' we tell the compiler "execute the function right
    // to the try, if this function returns an error return the error, else return the function"
    // In many other programming languages, this would look be done by adding a '?'
    try stdout.writeAll(std.fmt.comptimePrint("Hello, {s}!\n", .{"World"}));
}
