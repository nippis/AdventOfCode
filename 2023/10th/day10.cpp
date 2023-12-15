#include "../solutions.hh"

struct Pipe
{
  Pipe(char a, int x, int y) : shape(a), x(x), y(y) {}
  char shape;
  int x;
  int y;
  Pipe* a;
  Pipe* b;
};

std::pair<std::string, std::string> day10::solve(std::ifstream f)
{
  std::string line;
  std::vector<Pipe> pipes;
  int maxx = 0;
  int maxy = 0;
  {
    int y = 0;
    while (getline(f, line))
    {
      int x = 0;
      for (x = 0; x < line.size(); x++)
        if (line.at(x) != '.') pipes.push_back(Pipe(line.at(x), x,y));
      y++;
      maxy++;
      if (maxx == 0) maxx = x;
    }
  }

  Pipe* start = nullptr;

  for (auto& pipe : pipes)
  {
    if (pipe.shape == '|')
    {
      pipe.a = (pipe.y>0) ? &(*(std::find_if(pipes.begin(), pipes.end(), 
        [pipe](Pipe& pipe2){return (pipe2.x == pipe.x) && (pipe2.y == pipe.y-1);}))) : nullptr;
      pipe.b = (pipe.y<maxy-1) ? &(*(std::find_if(pipes.begin(), pipes.end(), 
        [pipe](Pipe& pipe2){return (pipe2.x == pipe.x) && (pipe2.y == pipe.y+1);}))) : nullptr;
    }
    else if (pipe.shape == '-')
    {
      pipe.a = (pipe.x>0) ? &(*(std::find_if(pipes.begin(), pipes.end(), 
        [pipe](Pipe& pipe2){return (pipe2.x == pipe.x-1) && (pipe2.y == pipe.y);}))) : nullptr;
      pipe.b = (pipe.x<maxx-1) ? &(*(std::find_if(pipes.begin(), pipes.end(), 
        [pipe](Pipe& pipe2){return (pipe2.x == pipe.x+1) && (pipe2.y == pipe.y);}))) : nullptr;
    }
    else if (pipe.shape == 'L')
    {
      pipe.a = (pipe.y>0) ? &(*(std::find_if(pipes.begin(), pipes.end(), 
        [pipe](Pipe& pipe2){return (pipe2.x == pipe.x) && (pipe2.y == pipe.y-1);}))) : nullptr;
      pipe.b = (pipe.x<maxx-1) ? &(*(std::find_if(pipes.begin(), pipes.end(), 
        [pipe](Pipe& pipe2){return (pipe2.x == pipe.x+1) && (pipe2.y == pipe.y);}))) : nullptr;
    }
    else if (pipe.shape == 'J')
    {
      pipe.a = (pipe.y>0) ? &(*(std::find_if(pipes.begin(), pipes.end(), 
        [pipe](Pipe& pipe2){return (pipe2.x == pipe.x) && (pipe2.y == pipe.y-1);}))) : nullptr;
      pipe.b = (pipe.x>0) ? &(*(std::find_if(pipes.begin(), pipes.end(), 
        [pipe](Pipe& pipe2){return (pipe2.x == pipe.x-1) && (pipe2.y == pipe.y);}))) : nullptr;
    }
    else if (pipe.shape == '7')
    {
      pipe.a = (pipe.x>0) ? &(*(std::find_if(pipes.begin(), pipes.end(), 
        [pipe](Pipe& pipe2){return (pipe2.x == pipe.x-1) && (pipe2.y == pipe.y);}))) : nullptr;
      pipe.b = (pipe.y<maxy-1) ? &(*(std::find_if(pipes.begin(), pipes.end(), 
        [pipe](Pipe& pipe2){return (pipe2.x == pipe.x) && (pipe2.y == pipe.y+1);}))) : nullptr;
    }
    else if (pipe.shape == 'F')
    {
      pipe.a = (pipe.x<maxx-1) ? &(*(std::find_if(pipes.begin(), pipes.end(), 
        [pipe](Pipe& pipe2){return (pipe2.x == pipe.x+1) && (pipe2.y == pipe.y);}))) : nullptr;
      pipe.b = (pipe.y<maxy-1) ? &(*(std::find_if(pipes.begin(), pipes.end(), 
        [pipe](Pipe& pipe2){return (pipe2.x == pipe.x) && (pipe2.y == pipe.y+1);}))) : nullptr;
    }
    else if (pipe.shape == 'S')
    {
      pipe.a = (pipe.y>0) ? &(*(std::find_if(pipes.begin(), pipes.end(), 
        [pipe](Pipe& pipe2){return (pipe2.x == pipe.x) && (pipe2.y == pipe.y-1);}))) : nullptr;
      pipe.b = (pipe.y<maxy-1) ? &(*(std::find_if(pipes.begin(), pipes.end(), 
        [pipe](Pipe& pipe2){return (pipe2.x == pipe.x) && (pipe2.y == pipe.y+1);}))) : nullptr;
      start = &pipe;
    }
  }

  int steps = 0;
  Pipe* pipe = start;
  Pipe* prev = nullptr;
  do
  {
    Pipe* prevtemp = pipe;
    pipe = (pipe->a != prev) ? pipe->a : pipe->b;
    prev = prevtemp;
    steps++;
  }
  while (pipe != start);

  steps /= 2;

  return {std::to_string(steps),""};
}