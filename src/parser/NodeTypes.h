/* Generated by Ruby Script! */

#pragma once

#include <cinttypes>

enum class SyntaxNodeType: std::int16_t {
    Invalid = 0,

    ArrayExpression,
    ArrayPattern,
    ArrowFunctionExpression,
    AssignmentExpression,
    AssignmentPattern,
    AwaitExpression,
    BinaryExpression,
    BlockStatement,
    BreakStatement,
    CallExpression,
    CatchClause,
    ClassBody,
    ClassDeclaration,
    ClassExpression,
    ConditionalExpression,
    ContinueStatement,
    DebuggerStatement,
    Directive,
    DoWhileStatement,
    EmptyStatement,
    ExportAllDeclaration,
    ExportDefaultDeclaration,
    ExportNamedDeclaration,
    ExportSpecifier,
    ExpressionStatement,
    ForInStatement,
    ForOfStatement,
    ForStatement,
    FunctionDeclaration,
    FunctionExpression,
    Identifier,
    IfStatement,
    Import,
    ImportDeclaration,
    ImportDefaultSpecifier,
    ImportNamespaceSpecifier,
    ImportSpecifier,
    LabeledStatement,
    Literal,
    MetaProperty,
    MethodDefinition,
    Module,
    NewExpression,
    ObjectExpression,
    ObjectPattern,
    Property,
    RegexLiteral,
    RestElement,
    ReturnStatement,
    Script,
    SequenceExpression,
    SpreadElement,
    MemberExpression,
    Super,
    SwitchCase,
    SwitchStatement,
    TaggedTemplateExpression,
    TemplateElement,
    TemplateLiteral,
    ThisExpression,
    ThrowStatement,
    TryStatement,
    UnaryExpression,
    UpdateExpression,
    VariableDeclaration,
    VariableDeclarator,
    WhileStatement,
    WithStatement,
    YieldExpression,
    ArrowParameterPlaceHolder,
    JSXClosingElement,
    JSXElement,
    JSXEmptyExpression,
    JSXExpressionContainer,
    JSXIdentifier,
    JSXMemberExpression,
    JSXAttribute,
    JSXNamespacedName,
    JSXOpeningElement,
    JSXSpreadAttribute,
    JSXText,
    TSParameterProperty,
    TSDeclareFunction,
    TSDeclareMethod,
    TSQualifiedName,
    TSCallSignatureDeclaration,
    TSConstructSignatureDeclaration,
    TSPropertySignature,
    TSMethodSignature,
    TSIndexSignature,
    TSAnyKeyword,
    TSBooleanKeyword,
    TSBigIntKeyword,
    TSNeverKeyword,
    TSNullKeyword,
    TSNumberKeyword,
    TSObjectKeyword,
    TSStringKeyword,
    TSSymbolKeyword,
    TSUndefinedKeyword,
    TSUnknownKeyword,
    TSVoidKeyword,
    TSThisType,
    TSFunctionType,
    TSConstructorType,
    TSTypeReference,
    TSTypePredicate,
    TSTypeQuery,
    TSTypeLiteral,
    TSArrayType,
    TSTupleType,
    TSOptionalType,
    TSRestType,
    TSUnionType,
    TSIntersectionType,
    TSConditionalType,
    TSInferType,
    TSParenthesizedType,
    TSTypeOperator,
    TSIndexedAccessType,
    TSMappedType,
    TSLiteralType,
    TSExpressionWithTypeArguments,
    TSInterfaceDeclaration,
    TSInterfaceBody,
    TSTypeAliasDeclaration,
    TSAsExpression,
    TSTypeAssertion,
    TSEnumDeclaration,
    TSEnumMember,
    TSModuleDeclaration,
    TSModuleBlock,
    TSImportType,
    TSImportEqualsDeclaration,
    TSExternalModuleReference,
    TSNonNullExpression,
    TSExportAssignment,
    TSNamespaceExportDeclaration,
    TSTypeAnnotation,
    TSTypeParameterInstantiation,
    TSTypeParameterDeclaration,
    TSTypeParameter,

};

static const char* SyntaxNodeTypeToString(SyntaxNodeType type_);

class ArrayExpression;
class ArrayPattern;
class ArrowFunctionExpression;
class AssignmentExpression;
class AssignmentPattern;
class AwaitExpression;
class BinaryExpression;
class BlockStatement;
class BreakStatement;
class CallExpression;
class CatchClause;
class ClassBody;
class ClassDeclaration;
class ClassExpression;
class ConditionalExpression;
class ContinueStatement;
class DebuggerStatement;
class Directive;
class DoWhileStatement;
class EmptyStatement;
class ExportAllDeclaration;
class ExportDefaultDeclaration;
class ExportNamedDeclaration;
class ExportSpecifier;
class ExpressionStatement;
class ForInStatement;
class ForOfStatement;
class ForStatement;
class FunctionDeclaration;
class FunctionExpression;
class Identifier;
class IfStatement;
class Import;
class ImportDeclaration;
class ImportDefaultSpecifier;
class ImportNamespaceSpecifier;
class ImportSpecifier;
class LabeledStatement;
class Literal;
class MetaProperty;
class MethodDefinition;
class Module;
class NewExpression;
class ObjectExpression;
class ObjectPattern;
class Property;
class RegexLiteral;
class RestElement;
class ReturnStatement;
class Script;
class SequenceExpression;
class SpreadElement;
class MemberExpression;
class Super;
class SwitchCase;
class SwitchStatement;
class TaggedTemplateExpression;
class TemplateElement;
class TemplateLiteral;
class ThisExpression;
class ThrowStatement;
class TryStatement;
class UnaryExpression;
class UpdateExpression;
class VariableDeclaration;
class VariableDeclarator;
class WhileStatement;
class WithStatement;
class YieldExpression;
class ArrowParameterPlaceHolder;
class JSXClosingElement;
class JSXElement;
class JSXEmptyExpression;
class JSXExpressionContainer;
class JSXIdentifier;
class JSXMemberExpression;
class JSXAttribute;
class JSXNamespacedName;
class JSXOpeningElement;
class JSXSpreadAttribute;
class JSXText;
class TSParameterProperty;
class TSDeclareFunction;
class TSDeclareMethod;
class TSQualifiedName;
class TSCallSignatureDeclaration;
class TSConstructSignatureDeclaration;
class TSPropertySignature;
class TSMethodSignature;
class TSIndexSignature;
class TSAnyKeyword;
class TSBooleanKeyword;
class TSBigIntKeyword;
class TSNeverKeyword;
class TSNullKeyword;
class TSNumberKeyword;
class TSObjectKeyword;
class TSStringKeyword;
class TSSymbolKeyword;
class TSUndefinedKeyword;
class TSUnknownKeyword;
class TSVoidKeyword;
class TSThisType;
class TSFunctionType;
class TSConstructorType;
class TSTypeReference;
class TSTypePredicate;
class TSTypeQuery;
class TSTypeLiteral;
class TSArrayType;
class TSTupleType;
class TSOptionalType;
class TSRestType;
class TSUnionType;
class TSIntersectionType;
class TSConditionalType;
class TSInferType;
class TSParenthesizedType;
class TSTypeOperator;
class TSIndexedAccessType;
class TSMappedType;
class TSLiteralType;
class TSExpressionWithTypeArguments;
class TSInterfaceDeclaration;
class TSInterfaceBody;
class TSTypeAliasDeclaration;
class TSAsExpression;
class TSTypeAssertion;
class TSEnumDeclaration;
class TSEnumMember;
class TSModuleDeclaration;
class TSModuleBlock;
class TSImportType;
class TSImportEqualsDeclaration;
class TSExternalModuleReference;
class TSNonNullExpression;
class TSExportAssignment;
class TSNamespaceExportDeclaration;
class TSTypeAnnotation;
class TSTypeParameterInstantiation;
class TSTypeParameterDeclaration;
class TSTypeParameter;
