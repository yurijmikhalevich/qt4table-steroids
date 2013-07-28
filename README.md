qt4table-steroids
=================

Now it provides three classes.

You can also generate code documentation using doxygen.

## SteroidsModel

Template model class (extends QSqlTableModel and QSqlRelationalTableModel), which provides additional filter
functionality. Every filter should store itself in this->filters QHash and, when we need update filters, we should
call compileFilters method.

## SteroidsView

Just preconfigured for most recently use case QTableView.

## SteroidsValidator

QValidator, extended to work with QLineEditDelegate, it can access Line Edit contents at moment of entering in editor
mode through modelData property.

## SpinBoxDelegate

Simple QSpinBox StyledItemDelegate, which constuctor accepts three additional arguments: minimum, maximum and
defaultValue.

## CheckBoxDelegate

Simple QCheckBox StyledItemDelegate designed to work with models, in which boolean values stored as 0 and 1.

## QLineEditDelegate

Simple LineEditDelegate, maybe provided with SteroidsValidator.
