int	check_same_value(int *box_arr, int value, int current_pos, int max_pos)
{
	int	row;
	int	col;
	int	pos;

	row =  (current_pos / max_pos) * max_pos;
	col = current_pos % max_pos;
	pos = row;
	while (box_arr[pos] != 0 && pos < row + max_pos && box_arr[pos++] == value)
			return (0);
	pos = col;
	while (box_arr[pos] != 0 && pos < max_pos * max_pos && box_arr[pos += max_pos] == value)
			return (0);
	box_arr[current_pos] = value;
	return (1);
}

int	check_up(int *box_arr, int *visible_box, int current_pos, int max_pos)
{
	int	col;
	int	pos;
	int	visible_cnt;
	int	max_box;

	col = current_pos % max_pos;
	pos = col;
	max_box = 0;
	visible_cnt = 0;
	while (box_arr[pos] != 0 && pos < max_pos * max_pos)
	{
		if (max_box < box_arr[pos])
		{
			max_box = box_arr[pos];
			visible_cnt++;
			if (max_box == max_pos)
			{
			    if (visible_cnt == visible_box[col])
			        return (1);
			    else
			        return (0);
			}
		}
		pos += max_pos;
	}
	if (visible_cnt > visible_box[col])
		return (0);
	return (1);
}

int	check_down(int *box_arr, int *visible_box, int current_pos, int max_pos)
{
	int	col;
	int	pos;
	int	visible_cnt;
	int	max_box;

	if (current_pos / max_pos != max_pos - 1)
		return (1);
	col = max_pos * (max_pos - 1) + current_pos % max_pos;
	pos = current_pos;
	max_box = 0;
	visible_cnt = 0;
	while (pos >= 0)
	{
		if (max_box < box_arr[pos])
		{
			max_box = box_arr[pos];
			visible_cnt++;
		}
		pos -= max_pos;
	}
	if (visible_cnt != visible_box[max_pos + current_pos % max_pos])
		return (0);
	return (1);
}

int	check_left(int *box_arr, int *visible_box, int current_pos, int max_pos)
{
	int	row;
	int	pos;
	int	visible_cnt;
	int	max_box;

	row = (current_pos / max_pos) * max_pos;
	pos = row;
	max_box = 0;
	visible_cnt = 0;
	while (box_arr[pos] != 0 && pos < row + max_pos)
	{
		if (max_box < box_arr[pos])
		{
			max_box = box_arr[pos];
			visible_cnt++;
			if (max_box == max_pos)
			{
			    if (visible_cnt == visible_box[2 * max_pos + current_pos / max_pos])
			        return (1);
			    else
			        return (0);
			}
		}
		pos += 1;
	}
	if (visible_cnt > visible_box[2 * max_pos + current_pos / max_pos])
		return (0);
	return (1);
}

int	check_right(int *box_arr, int *visible_box, int current_pos, int max_pos)
{
	int	row;
	int	pos;
	int	visible_cnt;
	int	max_box;

	
	if (current_pos % max_pos != max_pos - 1)
		return (1);
	row = current_pos / max_pos * max_pos;
	pos = current_pos;
	max_box = 0;
	visible_cnt = 0;
	while (pos >= row)
	{
		if (max_box < box_arr[pos])
		{
			max_box = box_arr[pos];
			visible_cnt++;
		}
		pos -= 1;
	}
	if (visible_cnt != visible_box[3 * max_pos + current_pos / max_pos])
		return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str++))
		i++;
	return (i);
}

int	backtracking(int *visible_box, int *box_arr, int val, int max_pos, int current_pos)
{
	if (current_pos == max_pos * max_pos)
		return (1);
	while (val <= max_pos)
	{
		if (check_same_value(box_arr, val, current_pos, max_pos)
			&& check_up(box_arr, visible_box, current_pos, max_pos)
			&& check_left(box_arr, visible_box, current_pos, max_pos)
			&& check_down(box_arr, visible_box, current_pos, max_pos)
			&& check_right(box_arr, visible_box, current_pos, max_pos))
		{
			if (backtracking(visible_box, box_arr, 1, max_pos, current_pos + 1))
			    return (1);
			val++;
		}
		else
		{
			box_arr[current_pos] = 0;
			val++;
		}
	}
	return (0);
}

int	rush(int *visible_box, int *box_arr, int box_cnt)
{
	int	pos;
	int	max_pos;

	pos = 0;
	max_pos = box_cnt / 4;
	if (backtracking(visible_box, box_arr, 1, max_pos, 0))
		return (1);
	else
		return (0);
}
