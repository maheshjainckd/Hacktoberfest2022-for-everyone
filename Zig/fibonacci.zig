const std = @import("std");

fn fibonacci(n: u64) u64 {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

pub fn main() !void {
    const stdout = std.io.getStdOut();

    var i: u32 = 0;
    var buf: [32]u8 = undefined;
    while (i < 50) : (i += 1) {
        try stdout.writeAll(try std.fmt.bufPrint(&buf, "n({}): {}\n", .{ i, fibonacci(i) }));
    }
}
