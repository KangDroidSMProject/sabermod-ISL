#ifndef ISL_UNION_MAP_H
#define ISL_UNION_MAP_H

#include <isl_dim.h>
#include <isl_map.h>
#include <isl_printer.h>

#if defined(__cplusplus)
extern "C" {
#endif

struct isl_union_map;
typedef struct isl_union_map isl_union_map;
#ifndef isl_union_set
struct isl_union_set;
typedef struct isl_union_set isl_union_set;
#endif

__isl_give isl_union_map *isl_union_map_from_map(__isl_take isl_map *map);
__isl_give isl_union_map *isl_union_map_empty(__isl_take isl_dim *dim);
__isl_give isl_union_map *isl_union_map_copy(__isl_keep isl_union_map *umap);
void isl_union_map_free(__isl_take isl_union_map *umap);

isl_ctx *isl_union_map_get_ctx(__isl_keep isl_union_map *umap);
__isl_give isl_dim *isl_union_map_get_dim(__isl_keep isl_union_map *umap);

__isl_give isl_union_set *isl_union_map_domain(__isl_take isl_union_map *umap);
__isl_give isl_union_set *isl_union_map_range(__isl_take isl_union_map *umap);

__isl_give isl_union_map *isl_union_map_affine_hull(
	__isl_take isl_union_map *umap);
__isl_give isl_union_map *isl_union_map_coalesce(
	__isl_take isl_union_map *umap);
__isl_give isl_union_map *isl_union_map_compute_divs(
	__isl_take isl_union_map *umap);
__isl_give isl_union_map *isl_union_map_lexmin(__isl_take isl_union_map *umap);
__isl_give isl_union_map *isl_union_map_lexmax(__isl_take isl_union_map *umap);

__isl_give isl_union_map *isl_union_map_add_map(__isl_take isl_union_map *umap,
	__isl_take isl_map *map);
__isl_give isl_union_map *isl_union_map_union(__isl_take isl_union_map *umap1,
	__isl_take isl_union_map *umap2);
__isl_give isl_union_map *isl_union_map_subtract(
	__isl_take isl_union_map *umap1, __isl_take isl_union_map *umap2);
__isl_give isl_union_map *isl_union_map_intersect(
	__isl_take isl_union_map *umap1, __isl_take isl_union_map *umap2);
__isl_give isl_union_map *isl_union_map_product(__isl_take isl_union_map *umap1,
	__isl_take isl_union_map *umap2);
__isl_give isl_union_map *isl_union_map_gist(__isl_take isl_union_map *umap,
	__isl_take isl_union_map *context);

__isl_give isl_union_map *isl_union_map_intersect_domain(
	__isl_take isl_union_map *umap, __isl_take isl_union_set *uset);

__isl_give isl_union_map *isl_union_map_apply_range(
	__isl_take isl_union_map *umap1, __isl_take isl_union_map *umap2);
__isl_give isl_union_map *isl_union_map_reverse(__isl_take isl_union_map *umap);
__isl_give isl_union_map *isl_union_map_from_domain_and_range(
	__isl_take isl_union_set *domain, __isl_take isl_union_set *range);

__isl_give isl_union_set *isl_union_map_deltas(__isl_take isl_union_map *umap);

int isl_union_map_is_empty(__isl_keep isl_union_map *umap);

int isl_union_map_is_subset(__isl_keep isl_union_map *umap1,
	__isl_keep isl_union_map *umap2);
int isl_union_map_is_equal(__isl_keep isl_union_map *umap1,
	__isl_keep isl_union_map *umap2);
int isl_union_map_is_strict_subset(__isl_keep isl_union_map *umap1,
	__isl_keep isl_union_map *umap2);

int isl_union_map_foreach_map(__isl_keep isl_union_map *umap,
	int (*fn)(__isl_take isl_map *map, void *user), void *user);

__isl_give isl_basic_map *isl_union_map_sample(__isl_take isl_union_map *umap);

__isl_give isl_union_map *isl_union_map_transitive_closure(
	__isl_take isl_union_map *umap, int *exact);

__isl_give isl_printer *isl_printer_print_union_map(__isl_take isl_printer *p,
	__isl_keep isl_union_map *umap);

__isl_give isl_union_set *isl_union_map_wrap(__isl_take isl_union_map *umap);
__isl_give isl_union_map *isl_union_set_unwrap(__isl_take isl_union_set *uset);

#if defined(__cplusplus)
}
#endif

#endif