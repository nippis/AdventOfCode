opp_shapes = ["A" "B" "C"].';
your_shapes = ["X" "Y" "Z"];
shape_points =  [1 2 3]; % rock paper scissors
result = [1 2 0; 0 1 2; 2 0 1]; % 0 loss, 1 draw, 2 win
result_factor = 3;
result_points = result*result_factor;

strategy_guide = readmatrix("input.txt", "OutputType", "string");

points = 0;
points_b = 0;
for i = 1:size(strategy_guide, 1)
    opp = [0 0 0].';
    you = [0 0 0];
    for j = 1:3
        opp(j) = (opp_shapes(j) == strategy_guide(i, 1));
        you(j) = (your_shapes(j) == strategy_guide(i, 2));
    end
    round = opp*you;
    points = points + result_points.*round + shape_points*you.'*round;

end
sum(points, 'all')