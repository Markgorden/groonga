/* -*- c-basic-offset: 2 -*- */
/*
  Copyright(C) 2015 Brazil

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License version 2.1 as published by the Free Software Foundation.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "../grn_ctx_impl.h"

#ifdef GRN_WITH_MRUBY
#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/hash.h>
#include <mruby/array.h>
#include <mruby/string.h>

#include "mrb_ctx.h"
#include "mrb_table_group_result.h"

static struct mrb_data_type mrb_grn_table_group_result_type = {
  "Groonga::TableGroupResult",
  mrb_free
};

static mrb_value
mrb_grn_table_group_result_initialize(mrb_state *mrb, mrb_value self)
{
  grn_table_group_result *result;

  DATA_TYPE(self) = &mrb_grn_table_group_result_type;

  result = mrb_calloc(mrb, 1, sizeof(grn_table_group_result));
  DATA_PTR(self) = result;

  return self;
}


static mrb_value
mrb_grn_table_group_result_close(mrb_state *mrb, mrb_value self)
{
  grn_table_group_result *result;

  result = DATA_PTR(self);
  if (result) {
    mrb_free(mrb, result);
    DATA_PTR(self) = NULL;
  }

  return mrb_nil_value();
}

void
grn_mrb_table_group_result_init(grn_ctx *ctx)
{
  grn_mrb_data *data = &(ctx->impl->mrb);
  mrb_state *mrb = data->state;
  struct RClass *module = data->module;
  struct RClass *klass;

  klass = mrb_define_class_under(mrb, module, "TableGroupResult",
                                 mrb->object_class);
  MRB_SET_INSTANCE_TT(klass, MRB_TT_DATA);

  mrb_define_method(mrb, klass, "initialize",
                    mrb_grn_table_group_result_initialize, MRB_ARGS_NONE());

  mrb_define_method(mrb, klass, "close",
                    mrb_grn_table_group_result_close, MRB_ARGS_NONE());
}
#endif