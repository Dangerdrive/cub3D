#include "cub3d.h"

vector_t vec_new(double x, double y)
{
	vector_t vec;
	vec.x = x;
	vec.y = y;
	return vec;
}

vector_t vec_add(vector_t vec1, vector_t vec2)
{
	return vec_new(vec1.x + vec2.x, vec1.y + vec2.y);
}

vector_t vec_sub(vector_t vec1, vector_t vec2)
{
	return vec_new(vec1.x - vec2.x, vec1.y - vec2.y);
}

vector_t vec_scale(vector_t vec, double scalar)
{
	return vec_new(vec.x * scalar, vec.y * scalar);
}

// Positive angle: clock-wise rotation
vector_t vec_rotate(vector_t vec, double angle)
{
	double		integer;
	double		decimal;
	double		radian;
	double		cos_a;
	double		sin_a;

	decimal = modf(angle, &integer);
	angle = (long)integer % 360 + decimal;
	radian = angle * DEG2RAD;
	cos_a = cos(radian);
	sin_a = sin(radian);
	return vec_new(vec.x*cos_a + vec.y*sin_a, -vec.x*sin_a + vec.y*cos_a);
}

double vec_dot(vector_t vec1, vector_t vec2)
{
	return (vec1.x * vec2.x) + (vec1.y * vec2.y);
}

double vec_length(vector_t vec)
{
	return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
}

vector_t vec_normal(vector_t vec)
{
	double	len;

	len = vec_length(vec);
	if (len == 0)
		return vec;
	return vec_scale(vec, 1/vec_length(vec));
}

double vec_angle(vector_t vec1, vector_t vec2)
{
	double	n = vec1.y * vec2.x - vec1.x * vec2.y;
	return atan2(n, vec_dot(vec1, vec2)) * RAD2DEG;
}

// Applies a function to each coordinate of 1 or more vectors
// Can probably be optimized
vector_t vec_func(double (*func)(double*), size_t vec_amt, ...)
{
	va_list		va_x;
	va_list		va_y;
	double*		vecs_x;
	double*		vecs_y;
	vector_t	ret;
	size_t		i;

	va_start(va_x, vec_amt);
	va_start(va_y, vec_amt);
	vecs_x = malloc(vec_amt * sizeof(double));
	vecs_y = malloc(vec_amt * sizeof(double));
	i = 0;
	while (i++ <= vec_amt)
	{
		vecs_x[i-1] = va_arg(va_x, vector_t).x;
		vecs_y[i-1] = va_arg(va_y, vector_t).y;
	}
	va_end(va_x);
	va_end(va_y);
	ret = vec_new(func(vecs_x), func(vecs_y));
	free(vecs_x);
	free(vecs_y);
	return ret;
}

void vec_print(vector_t vec)
{
	printf("(%f, %f)\n", vec.x, vec.y);
}
