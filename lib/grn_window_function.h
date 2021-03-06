/*
  Copyright(C) 2016 Brazil

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#pragma once

struct _grn_window {
  grn_obj *table;
  grn_obj ids;
  size_t n_ids;
  ssize_t current_index;
  grn_window_direction direction;
  grn_table_sort_key *sort_keys;
  size_t n_sort_keys;
};

grn_rc grn_window_init(grn_ctx *ctx, grn_window *window, grn_obj *table);
grn_rc grn_window_fin(grn_ctx *ctx, grn_window *window);
grn_rc grn_window_set_sort_keys(grn_ctx *ctx,
                                grn_window *window,
                                grn_table_sort_key *sort_keys,
                                size_t n_sort_keys);

#ifdef __cplusplus
}
#endif
