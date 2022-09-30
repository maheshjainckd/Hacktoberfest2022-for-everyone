const std = @import("std");

inline fn fibonacci(comptime n: u64) u64 {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

pub fn main() !void {
    const stdout = std.io.getStdOut();

    comptime var i = 0;
    inline while (i < 50) : (i += 1) {
        try stdout.writeAll(std.fmt.comptimePrint("n({}): {}\n", .{ i, comptime fibonacci(i) }));
    }
}
