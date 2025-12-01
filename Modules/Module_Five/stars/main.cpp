#include <print>
#include <string>

using std::println;

void print_stars(int star_count)
{
	if (star_count == 0)
	{
		return;
	}

	for (int i = 0; i < star_count; i++)
	{
		std::print("*");
	}
	println();

	print_stars(star_count - 1);

	for (int i = 0; i < star_count; i++)
	{
		std::print("*");
	}
	println();
}

int main(int argc, char** argv)
{
	if (argc < 2)
	{
		println("Usage: {} <star_depth> [star_lines]", argv[0]);
		return -1;
	}

	int star_depth;
	if (argc >= 3)
	{
		int star_lines = std::stoi(argv[2]) / 2;
		if (star_lines < 1)
		{
			println("Star lines must be > 0");
			return -1;
		}
		star_depth = star_lines;
	}
	else
	{
		star_depth = std::stoi(argv[1]);
		if (star_depth < 1)
		{
			println("Star depth must be > 0");
			return -1;
		}
	}

	print_stars(star_depth);
}
