## Resources

https://lodev.org/cgtutor/raycasting.html

https://reactive.so/post/42-a-comprehensive-guide-to-cub3d/
Make Your Own Raycaster Part 1
https://www.youtube.com/watch?v=gYRrGTC7GtA&ab_channel=3DSage

https://medium.com/@afatir.ahmedfatir/cub3d-tutorial-af5dd31d2fcf


/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d jhj.cub                                                                                                                                                                                                          19:16
Error: map file could not be opened
[1]    47633 segmentation fault (core dumped)  ./cub3d jhj.cub


[ok] wrong number of arguments
[ok] wrong extension

[ko] map that doesnt exist

./cub3d maps/map_samples.cub                                                                                                                                                                                        19:45
Error: map file could not be opened
[1]    54822 segmentation fault (core dumped)  ./cub3d maps/map_samples.cub
/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d mapss/map_samples.cub                                                                                                                                                                                       19:48
Error: map file could not be opened
[1]    54922 segmentation fault (core dumped)  ./cub3d mapss/map_samples.cub
/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d samples.cub                                                                                                                                                                                                 19:48
Error: map file could not be opened
[1]    54994 segmentation fault (core dumped)  ./cub3d samples.cub
/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d maps/map_sample.cub                                                                                                                                                                                         19:48
Texture error: invalid texture path.
[1]    55353 segmentation fault (core dumped)  ./cub3d maps/map_sample.cub
/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d maps/map_sample.cub                                                                                                                                                                                         19:50
Texture error: duplicated texture path.
[1]    55513 segmentation fault (core dumped)  ./cub3d maps/map_sample.cub
/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d maps/map_sample.cub                                                                                                                                                                                         19:51
[1]    55644 killed     ./cub3d maps/map_sample.cub
/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d maps/map_sample.cub                                                                                                                                                                                         19:51
Error: invalid color(s).
Please input valid RGB color(s) in theformat "R,G,B", where R, G, and B are integer values between 0 and 255.

/media/fde-alen/6446E14146E11498/Users/felip/source/repos/cub3d/ dev_updt_raycasting*
./cub3d maps/map_sample.cub                                                                                                                                                                                         19:52
Error: map file has invalid line.
[1]    55946 segmentation fault (core dumped)  ./cub3d maps/map_sample.cub


valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup

./content_map:
1.0-incomplete_map.cub  3.0-unidentified_content.cub  4.1-map_after_map.cub
2.0-map_no_player.cub   3.1-wrong_char.cub
2.1-double_player.cub   4.0-element_after_map.cub

./info:
1.0-invalid_ext.cbb             2.6-map_texture_more_then_complete.cub
1.1-empty_file.cub              2.7-map_wrong_SO_texture.cub
1.2-only_map.cub                3.0-wrong_color_content.cub
2.0-double_texture.cub          3.1-map_duplicate_color.cub
2.1-missing_texture.cub         3.2-map_missing_color.cub
2.2-wrong_texture_content.cub   3.3-double_color.cub
2.3-wrong_texture_ext.cub       3.4-map_wrong_color.cub
2.4-map_duplicate_WE.cub        4.0-mixed_infos_OKAY.cub
2.5-map_texture_incomplete.cub

./wall:
1-open_wall_left.cub   4-open_wall.cub          7-open_line.cub
2-open_wall_right.cub  5-map_leaky_borders.cub
3-open_wall_down.cub   6-open_inside.cub


valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/content_map/1.0-incomplete_map.cub
Error: invalid map edges.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/content_map/2.0-map_no_player.cub
Error: map contains invalid number of players

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/content_map/2.1-double_player.cub
Error: map contains invalid number of players

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/content_map/3.0-unidentified_content.cub
Error: invalid map


valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/content_map/3.1-wrong_char.cub
Error: map contains invalid characters

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/content_map/4.0-element_after_map.cub
Error: map file has invalid line.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/content_map/4.1-map_after_map.cub
Error: invalid map

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/1.0-invalid_ext.cbb
Error: invalid map extension

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/1.1-empty_file.cub
Error: map file could not be read.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/1.2-only_map.cub
Error: map file has invalid line.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.0-double_texture.cub
Texture error: duplicated texture path.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.1-missing_texture.cub
Error: map file has invalid line.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.2-wrong_texture_content.cub
Texture error: invalid texture path.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.3-wrong_texture_ext.cub
Texture error: invalid texture path.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.4-map_duplicate_WE.cub
Texture error: duplicated direction.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.5-map_texture_incomplete.cub
Texture error: cannot open texture.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.6-map_texture_more_then_complete.cub
Texture error: invalid texture path.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/2.7-map_wrong_SO_texture.cub
Texture error: cannot open texture.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/3.0-wrong_color_content.cub
Error: invalid color(s).
Please input valid RGB color(s) in theformat "R,G,B", where R, G, and B are integer values between 0 and 255.

Check leaks

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/3.1-map_duplicate_color.cub
Error: duplicated color.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/3.2-map_missing_color.cub
Error: map file has invalid line.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/3.3-double_color.cub
Error: duplicated color.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/3.4-map_wrong_color.cub
Error: invalid color(s).
Please input valid RGB color(s) in theformat "R,G,B", where R, G, and B are integer values between 0 and 255.

CHECK LEAKS

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/info/4.0-mixed_infos_OKAY.cub



valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/wall/1-open_wall_left.cub
Error: invalid map extern walls.
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/wall/2-open_wall_right.cub
Error: invalid map extern walls.
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/wall/3-open_wall_down.cub
Error: invalid map extern walls.
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/wall/5-map_leaky_borders.cub
Error: invalid map extern walls.

valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/wall/6-open_inside.cub
Error: invalid map edges.
valgrind --leak-check=full --show-leak-kinds=all --suppressions=./suppress.sup ./cub3d maps/error_maps/wall/7-open_line.cub

