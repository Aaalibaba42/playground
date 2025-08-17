import Data.List (minimumBy)
import Data.Ord (comparing)

part1 :: (Int, Int) -> [Int] -> Int
part1 (lo, hi) xs =
    sum [x | (i, x) <- zip [0..] xs, lo <= i, i <= hi]

manhattan :: (Int, Int) -> (Int, Int) -> Int
manhattan (x1, y1) (x2, y2) =
    abs (x1 - x2) + abs (y1 - y2)

part2 :: (Int, Int) -> [(Int, Int)] -> Int
part2 point coords =
    snd $ minimumBy (comparing fst)
        [ (manhattan point coord, i)
        | (i, coord@(x,y)) <- zip [0..] coords
        , fst point == x || snd point == y
        ]

main :: IO ()
main = do
    print $ part1 (0,2) [-2,0,3,-5,2,-1]
    print $ part1 (1,3) [1,-2,3,-4,5]

    print $ part2 (3,4) [(1,2),(3,1),(2,4),(2,3)]
    print $ part2 (2,5) [(3,4),(2,3),(1,5),(2,5)]
