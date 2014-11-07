#ifndef __SELECT_STATEMENT_H__
#define __SELECT_STATEMENT_H__

#include "Statement.h"
#include "Expr.h"
#include "List.h"
#include "Table.h"

namespace hsql {


/**
 * @struct OrderDescription
 * Description of the order by clause within a select statement
 * TODO: hold multiple expressions to be sorted by
 */
typedef enum {
	kOrderAsc,
	kOrderDesc
} OrderType;

struct OrderDescription {
	OrderDescription(OrderType type, Expr* expr) : type(type), expr(expr) {}
	OrderType type;
	Expr* expr;	
};

/**
 * @struct LimitDescription
 * Description of the limit clause within a select statement
 */
const int64_t kNoLimit = -1;
const int64_t kNoOffset = -1;
struct LimitDescription {
	LimitDescription(int64_t limit, int64_t offset) : limit(limit), offset(offset) {}
	int64_t limit;
	int64_t offset;	
};

/**
 * @struct SelectStatement
 * Representation of a full select statement.
 */
struct SelectStatement : Statement {
	SelectStatement() : Statement(kStmtSelect) {};

	TableRef* from_table;
	List<Expr*>* select_list;
	Expr* where_clause;
	
	List<Expr*>* group_by;

	OrderDescription* order;
	LimitDescription* limit;
};


} // namespace hsql

#endif