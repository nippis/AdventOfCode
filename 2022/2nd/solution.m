opp_shapes = ["A" "B" "C"].';
your_shapes = ["X" "Y" "Z"];
shape_points =  [1 2 3];
result = [1 2 0; 0 1 2; 2 0 1];
result_factor = 3;
result_points = result*result_factor;

strategy_guide = readmatrix("input.txt", "OutputType", "string");
points = 0;
points_b = 0;
for i = 1:size(strategy_guide, 1)
    opp = find(opp_shapes == strategy_guide(i, 1));
    you = find(your_shapes == strategy_guide(i, 2));
    points = points + shape_points(you) + result_points(opp, you);
    shape = find(result(opp,:) == you-1);
    points_b = points_b + result_points(2, you) + shape_points(x) ;
end
points
points_b
