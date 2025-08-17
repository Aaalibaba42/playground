fn part1(range: (u32, u32), list: &[i32]) -> i32 {
    list.iter()
        .enumerate()
        .filter(|(i, _)| range.0 <= *i as u32 && *i as u32 <= range.1)
        .map(|(_, &val)| val)
        .fold(0, |acc, x| acc + x)
}

fn part2(point: (u32, u32), coords: &[(u32, u32)]) -> usize {
    coords
        .iter()
        .enumerate()
        .filter(|(_, &(x, y))| point.0 == x || point.1 == y)
        .map(|(i, &(x, y))| {
            let dist = (x as i64 - point.0 as i64).abs() + (y as i64 - point.1 as i64).abs();
            (dist, i)
        })
        .min_by_key(|&(dist, _)| dist)
        .unwrap()
        .1
}

fn main() {
    println!("{}", part1((0, 2), &[-2, 0, 3, -5, 2, -1]));
    println!("{}", part1((1, 3), &[1, -2, 3, -4, 5]));

    println!("{}", part2((3, 4), &[(1, 2), (3, 1), (2, 4), (2, 3)]));
    println!("{}", part2((2, 5), &[(3, 4), (2, 3), (1, 5), (2, 5)]));
}
