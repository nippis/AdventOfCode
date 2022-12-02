opp_shapes = ["A" "B" "C"].';
your_shapes = ["X" "Y" "Z"];
shapes =  [1 2 3]; % rock paper scissors
results = [1 2 0; 0 1 2; 2 0 1]; % 0 loss, 1 draw, 2 win
factor = 3;

guide = readmatrix("input.txt", "OutputType", "string"); % Strategy guide

a = 0;
b = 0;
for i = 1:size(guide, 1)
    opp = opp_shapes == guide(i, 1);
    you = your_shapes == guide(i, 2);
    round = opp*you;
    a = a + results.*round*factor + shapes*you.'*round;
    desired_shapes = you*results(2,:).'*ones(3) == results;
    b = b + opp.'*desired_shapes*shapes.' + you*results(2,:).'*factor;
end

a = sum(a, 'all')
b













