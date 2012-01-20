/* converted from java package java.sql */
/*     by Kapi-Generator, yukkiwakka >:3 */

/*------------------------------------------------------------*/
/* unknown or another package classes .. */
class Java_io_InputStream;
class Java_io_OutputStream;
class Java_io_PrintStream;
class Java_io_PrintWriter;
class Java_io_Reader;
class Java_io_Writer;
class Java_lang_Enum;
class Java_lang_Exception;
class Java_lang_Throwable;
class Java_math_BigDecimal;
class Java_net_URL;
class Java_security_BasicPermission;
class Java_util_Calendar;
class Java_util_Date;
class Java_util_Enumeration;
class Java_util_Iterator;
class Java_util_Map;
class Java_util_Properties;
class Java_util_concurrent_Executor;
class Java_util_logging_Logger;

/*------------------------------------------------------------*/
/* this package classes .. */
class Java_sql_Array;
class Java_sql_SQLException extends Java_lang_Exception;
class Java_sql_BatchUpdateException extends Java_sql_SQLException;
class Java_sql_Blob;
class Java_sql_CallableStatement;
class Java_sql_ClientInfoStatus extends Java_lang_Enum;
class Java_sql_Clob;
class Java_sql_Connection;
class Java_sql_SQLWarning extends Java_sql_SQLException;
class Java_sql_DataTruncation extends Java_sql_SQLWarning;
class Java_sql_DatabaseMetaData;
class Java_sql_Date extends Java_util_Date;
class Java_sql_Driver;
class Java_sql_DriverManager;
class Java_sql_DriverPropertyInfo;
class Java_sql_NClob;
class Java_sql_ParameterMetaData;
class Java_sql_PreparedStatement;
class Java_sql_PseudoColumnUsage extends Java_lang_Enum;
class Java_sql_Ref;
class Java_sql_ResultSet;
class Java_sql_ResultSetMetaData;
class Java_sql_RowId;
class Java_sql_RowIdLifetime extends Java_lang_Enum;
class Java_sql_SQLClientInfoException extends Java_sql_SQLException;
class Java_sql_SQLData;
class Java_sql_SQLNonTransientException extends Java_sql_SQLException;
class Java_sql_SQLDataException extends Java_sql_SQLNonTransientException;
class Java_sql_SQLFeatureNotSupportedException extends Java_sql_SQLNonTransientException;
class Java_sql_SQLInput;
class Java_sql_SQLIntegrityConstraintViolationException extends Java_sql_SQLNonTransientException;
class Java_sql_SQLInvalidAuthorizationSpecException extends Java_sql_SQLNonTransientException;
class Java_sql_SQLNonTransientConnectionException extends Java_sql_SQLNonTransientException;
class Java_sql_SQLOutput;
class Java_sql_SQLPermission extends Java_security_BasicPermission;
class Java_sql_SQLRecoverableException extends Java_sql_SQLException;
class Java_sql_SQLSyntaxErrorException extends Java_sql_SQLNonTransientException;
class Java_sql_SQLTransientException extends Java_sql_SQLException;
class Java_sql_SQLTimeoutException extends Java_sql_SQLTransientException;
class Java_sql_SQLTransactionRollbackException extends Java_sql_SQLTransientException;
class Java_sql_SQLTransientConnectionException extends Java_sql_SQLTransientException;
class Java_sql_SQLXML;
class Java_sql_Savepoint;
class Java_sql_Statement;
class Java_sql_Struct;
class Java_sql_Time extends Java_util_Date;
class Java_sql_Timestamp extends Java_util_Date;
class Java_sql_Types;
class Java_sql_Wrapper;

/*------------------------------------------------------------*/
/* interface java.sql.Array */
class Java_sql_Array {
	/*-- Method --*/
	@Virtual @Overload void free();
	@Virtual @Overload Object getArray();
	@Virtual @Overload Object getArray(Java_util_Map p0);
	@Virtual @Overload Object getArray(long p0, int p1);
	@Virtual @Overload Object getArray(long p0, int p1, Java_util_Map p2);
	@Virtual @Overload int getBaseType();
	@Virtual @Overload String getBaseTypeName();
	@Virtual @Overload Java_sql_ResultSet getResultSet();
	@Virtual @Overload Java_sql_ResultSet getResultSet(Java_util_Map p0);
	@Virtual @Overload Java_sql_ResultSet getResultSet(long p0, int p1);
	@Virtual @Overload Java_sql_ResultSet getResultSet(long p0, int p1, Java_util_Map p2);
}

/* class java.sql.BatchUpdateException */
class Java_sql_BatchUpdateException extends Java_sql_SQLException {
	/*-- Method --*/
	@Virtual @Overload int[] getUpdateCounts();
}
@Overload Java_sql_BatchUpdateException Java_sql_BatchUpdateException.new(String p0, String p1, int p2, int[] p3);
@Overload Java_sql_BatchUpdateException Java_sql_BatchUpdateException.new(String p0, String p1, int[] p2);
@Overload Java_sql_BatchUpdateException Java_sql_BatchUpdateException.new(String p0, int[] p1);
@Overload Java_sql_BatchUpdateException Java_sql_BatchUpdateException.new(int[] p0);
@Overload Java_sql_BatchUpdateException Java_sql_BatchUpdateException.new();
@Overload Java_sql_BatchUpdateException Java_sql_BatchUpdateException.new(Java_lang_Throwable p0);
@Overload Java_sql_BatchUpdateException Java_sql_BatchUpdateException.new(int[] p0, Java_lang_Throwable p1);
@Overload Java_sql_BatchUpdateException Java_sql_BatchUpdateException.new(String p0, int[] p1, Java_lang_Throwable p2);
@Overload Java_sql_BatchUpdateException Java_sql_BatchUpdateException.new(String p0, String p1, int[] p2, Java_lang_Throwable p3);
@Overload Java_sql_BatchUpdateException Java_sql_BatchUpdateException.new(String p0, String p1, int p2, int[] p3, Java_lang_Throwable p4);

/* interface java.sql.Blob */
class Java_sql_Blob {
	/*-- Method --*/
	@Virtual @Overload void free();
	@Virtual @Overload Java_io_InputStream getBinaryStream();
	@Virtual @Overload Java_io_InputStream getBinaryStream(long p0, long p1);
	@Virtual @Overload int[] getBytes(long p0, int p1);
	@Virtual @Overload long length();
	@Virtual @Overload long position(int[] p0, long p1);
	@Virtual @Overload long position(Java_sql_Blob p0, long p1);
	@Virtual @Overload Java_io_OutputStream setBinaryStream(long p0);
	@Virtual @Overload int setBytes(long p0, int[] p1);
	@Virtual @Overload int setBytes(long p0, int[] p1, int p2, int p3);
	@Virtual @Overload void truncate(long p0);
}

/* interface java.sql.CallableStatement */
class Java_sql_CallableStatement {
	// implements java.sql.PreparedStatement
	/*-- Method --*/
	@Virtual @Overload Java_sql_Array getArray(int p0);
	@Virtual @Overload Java_sql_Array getArray(String p0);
	@Virtual @Overload Java_math_BigDecimal getBigDecimal(int p0, int p1);
	@Virtual @Overload Java_math_BigDecimal getBigDecimal(int p0);
	@Virtual @Overload Java_math_BigDecimal getBigDecimal(String p0);
	@Virtual @Overload Java_sql_Blob getBlob(int p0);
	@Virtual @Overload Java_sql_Blob getBlob(String p0);
	@Virtual @Overload boolean getBoolean(int p0);
	@Virtual @Overload boolean getBoolean(String p0);
	@Virtual @Overload int getByte(int p0);
	@Virtual @Overload int getByte(String p0);
	@Virtual @Overload int[] getBytes(int p0);
	@Virtual @Overload int[] getBytes(String p0);
	@Virtual @Overload Java_io_Reader getCharacterStream(int p0);
	@Virtual @Overload Java_io_Reader getCharacterStream(String p0);
	@Virtual @Overload Java_sql_Clob getClob(int p0);
	@Virtual @Overload Java_sql_Clob getClob(String p0);
	@Virtual @Overload Java_sql_Date getDate(int p0);
	@Virtual @Overload Java_sql_Date getDate(int p0, Java_util_Calendar p1);
	@Virtual @Overload Java_sql_Date getDate(String p0);
	@Virtual @Overload Java_sql_Date getDate(String p0, Java_util_Calendar p1);
	@Virtual @Overload double getDouble(int p0);
	@Virtual @Overload double getDouble(String p0);
	@Virtual @Overload float getFloat(int p0);
	@Virtual @Overload float getFloat(String p0);
	@Virtual @Overload int getInt(int p0);
	@Virtual @Overload int getInt(String p0);
	@Virtual @Overload long getLong(int p0);
	@Virtual @Overload long getLong(String p0);
	@Virtual @Overload Java_io_Reader getNCharacterStream(int p0);
	@Virtual @Overload Java_io_Reader getNCharacterStream(String p0);
	@Virtual @Overload Java_sql_NClob getNClob(int p0);
	@Virtual @Overload Java_sql_NClob getNClob(String p0);
	@Virtual @Overload String getNString(int p0);
	@Virtual @Overload String getNString(String p0);
	@Virtual @Overload Object getObject(int p0);
	@Virtual @Overload Object getObject(int p0, Java_util_Map p1);
	@Virtual @Overload Object getObject(String p0);
	@Virtual @Overload Object getObject(String p0, Java_util_Map p1);
	@Virtual @Overload Object getObject(int p0, Class p1);
	@Virtual @Overload Object getObject(String p0, Class p1);
	@Virtual @Overload Java_sql_Ref getRef(int p0);
	@Virtual @Overload Java_sql_Ref getRef(String p0);
	@Virtual @Overload Java_sql_RowId getRowId(int p0);
	@Virtual @Overload Java_sql_RowId getRowId(String p0);
	@Virtual @Overload Java_sql_SQLXML getSQLXML(int p0);
	@Virtual @Overload Java_sql_SQLXML getSQLXML(String p0);
	@Virtual @Overload int getShort(int p0);
	@Virtual @Overload int getShort(String p0);
	@Virtual @Overload String getString(int p0);
	@Virtual @Overload String getString(String p0);
	@Virtual @Overload Java_sql_Time getTime(int p0);
	@Virtual @Overload Java_sql_Time getTime(int p0, Java_util_Calendar p1);
	@Virtual @Overload Java_sql_Time getTime(String p0);
	@Virtual @Overload Java_sql_Time getTime(String p0, Java_util_Calendar p1);
	@Virtual @Overload Java_sql_Timestamp getTimestamp(int p0);
	@Virtual @Overload Java_sql_Timestamp getTimestamp(int p0, Java_util_Calendar p1);
	@Virtual @Overload Java_sql_Timestamp getTimestamp(String p0);
	@Virtual @Overload Java_sql_Timestamp getTimestamp(String p0, Java_util_Calendar p1);
	@Virtual @Overload Java_net_URL getURL(int p0);
	@Virtual @Overload Java_net_URL getURL(String p0);
	@Virtual @Overload void registerOutParameter(int p0, int p1);
	@Virtual @Overload void registerOutParameter(int p0, int p1, int p2);
	@Virtual @Overload void registerOutParameter(int p0, int p1, String p2);
	@Virtual @Overload void registerOutParameter(String p0, int p1);
	@Virtual @Overload void registerOutParameter(String p0, int p1, int p2);
	@Virtual @Overload void registerOutParameter(String p0, int p1, String p2);
	@Virtual @Overload void setAsciiStream(String p0, Java_io_InputStream p1, int p2);
	@Virtual @Overload void setAsciiStream(String p0, Java_io_InputStream p1, long p2);
	@Virtual @Overload void setAsciiStream(String p0, Java_io_InputStream p1);
	@Virtual @Overload void setBigDecimal(String p0, Java_math_BigDecimal p1);
	@Virtual @Overload void setBinaryStream(String p0, Java_io_InputStream p1, int p2);
	@Virtual @Overload void setBinaryStream(String p0, Java_io_InputStream p1, long p2);
	@Virtual @Overload void setBinaryStream(String p0, Java_io_InputStream p1);
	@Virtual @Overload void setBlob(String p0, Java_io_InputStream p1, long p2);
	@Virtual @Overload void setBlob(String p0, Java_sql_Blob p1);
	@Virtual @Overload void setBlob(String p0, Java_io_InputStream p1);
	@Virtual @Overload void setBoolean(String p0, boolean p1);
	@Virtual @Overload void setByte(String p0, int p1);
	@Virtual @Overload void setBytes(String p0, int[] p1);
	@Virtual @Overload void setCharacterStream(String p0, Java_io_Reader p1, int p2);
	@Virtual @Overload void setCharacterStream(String p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void setCharacterStream(String p0, Java_io_Reader p1);
	@Virtual @Overload void setClob(String p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void setClob(String p0, Java_sql_Clob p1);
	@Virtual @Overload void setClob(String p0, Java_io_Reader p1);
	@Virtual @Overload void setDate(String p0, Java_sql_Date p1);
	@Virtual @Overload void setDate(String p0, Java_sql_Date p1, Java_util_Calendar p2);
	@Virtual @Overload void setDouble(String p0, double p1);
	@Virtual @Overload void setFloat(String p0, float p1);
	@Virtual @Overload void setInt(String p0, int p1);
	@Virtual @Overload void setLong(String p0, long p1);
	@Virtual @Overload void setNCharacterStream(String p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void setNCharacterStream(String p0, Java_io_Reader p1);
	@Virtual @Overload void setNClob(String p0, Java_sql_NClob p1);
	@Virtual @Overload void setNClob(String p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void setNClob(String p0, Java_io_Reader p1);
	@Virtual @Overload void setNString(String p0, String p1);
	@Virtual @Overload void setNull(String p0, int p1);
	@Virtual @Overload void setNull(String p0, int p1, String p2);
	@Virtual @Overload void setObject(String p0, Object p1, int p2, int p3);
	@Virtual @Overload void setObject(String p0, Object p1, int p2);
	@Virtual @Overload void setObject(String p0, Object p1);
	@Virtual @Overload void setRowId(String p0, Java_sql_RowId p1);
	@Virtual @Overload void setSQLXML(String p0, Java_sql_SQLXML p1);
	@Virtual @Overload void setShort(String p0, int p1);
	@Virtual @Overload void setString(String p0, String p1);
	@Virtual @Overload void setTime(String p0, Java_sql_Time p1);
	@Virtual @Overload void setTime(String p0, Java_sql_Time p1, Java_util_Calendar p2);
	@Virtual @Overload void setTimestamp(String p0, Java_sql_Timestamp p1);
	@Virtual @Overload void setTimestamp(String p0, Java_sql_Timestamp p1, Java_util_Calendar p2);
	@Virtual @Overload void setURL(String p0, Java_net_URL p1);
	@Virtual @Overload boolean wasNull();
}

/* class java.sql.ClientInfoStatus */
class Java_sql_ClientInfoStatus extends Java_lang_Enum {
	/*-- Method --*/
	@Virtual @Overload Java_sql_ClientInfoStatus valueOf(String p0);
	@Virtual @Overload Java_sql_ClientInfoStatus[] values();
}

/* interface java.sql.Clob */
class Java_sql_Clob {
	/*-- Method --*/
	@Virtual @Overload void free();
	@Virtual @Overload Java_io_InputStream getAsciiStream();
	@Virtual @Overload Java_io_Reader getCharacterStream();
	@Virtual @Overload Java_io_Reader getCharacterStream(long p0, long p1);
	@Virtual @Overload String getSubString(long p0, int p1);
	@Virtual @Overload long length();
	@Virtual @Overload long position(String p0, long p1);
	@Virtual @Overload long position(Java_sql_Clob p0, long p1);
	@Virtual @Overload Java_io_OutputStream setAsciiStream(long p0);
	@Virtual @Overload Java_io_Writer setCharacterStream(long p0);
	@Virtual @Overload int setString(long p0, String p1);
	@Virtual @Overload int setString(long p0, String p1, int p2, int p3);
	@Virtual @Overload void truncate(long p0);
}

/* interface java.sql.Connection */
class Java_sql_Connection {
	// implements java.sql.Wrapper, java.lang.AutoCloseable
	/*-- Method --*/
	@Virtual @Overload void abort(Java_util_concurrent_Executor p0);
	@Virtual @Overload void clearWarnings();
	@Virtual @Overload void close();
	@Virtual @Overload void commit();
	@Virtual @Overload Java_sql_Array createArrayOf(String p0, Object[] p1);
	@Virtual @Overload Java_sql_Blob createBlob();
	@Virtual @Overload Java_sql_Clob createClob();
	@Virtual @Overload Java_sql_NClob createNClob();
	@Virtual @Overload Java_sql_SQLXML createSQLXML();
	@Virtual @Overload Java_sql_Statement createStatement();
	@Virtual @Overload Java_sql_Statement createStatement(int p0, int p1);
	@Virtual @Overload Java_sql_Statement createStatement(int p0, int p1, int p2);
	@Virtual @Overload Java_sql_Struct createStruct(String p0, Object[] p1);
	@Virtual @Overload boolean getAutoCommit();
	@Virtual @Overload String getCatalog();
	@Virtual @Overload String getClientInfo(String p0);
	@Virtual @Overload Java_util_Properties getClientInfo();
	@Virtual @Overload int getHoldability();
	@Virtual @Overload Java_sql_DatabaseMetaData getMetaData();
	@Virtual @Overload int getNetworkTimeout();
	@Virtual @Overload String getSchema();
	@Virtual @Overload int getTransactionIsolation();
	@Virtual @Overload Java_util_Map getTypeMap();
	@Virtual @Overload Java_sql_SQLWarning getWarnings();
	@Virtual @Overload boolean isClosed();
	@Virtual @Overload boolean isReadOnly();
	@Virtual @Overload boolean isValid(int p0);
	@Virtual @Overload String nativeSQL(String p0);
	@Virtual @Overload Java_sql_CallableStatement prepareCall(String p0);
	@Virtual @Overload Java_sql_CallableStatement prepareCall(String p0, int p1, int p2);
	@Virtual @Overload Java_sql_CallableStatement prepareCall(String p0, int p1, int p2, int p3);
	@Virtual @Overload Java_sql_PreparedStatement prepareStatement(String p0);
	@Virtual @Overload Java_sql_PreparedStatement prepareStatement(String p0, int p1, int p2);
	@Virtual @Overload Java_sql_PreparedStatement prepareStatement(String p0, int p1, int p2, int p3);
	@Virtual @Overload Java_sql_PreparedStatement prepareStatement(String p0, int p1);
	@Virtual @Overload Java_sql_PreparedStatement prepareStatement(String p0, int[] p1);
	@Virtual @Overload Java_sql_PreparedStatement prepareStatement(String p0, String[] p1);
	@Virtual @Overload void releaseSavepoint(Java_sql_Savepoint p0);
	@Virtual @Overload void rollback();
	@Virtual @Overload void rollback(Java_sql_Savepoint p0);
	@Virtual @Overload void setAutoCommit(boolean p0);
	@Virtual @Overload void setCatalog(String p0);
	@Virtual @Overload void setClientInfo(String p0, String p1);
	@Virtual @Overload void setClientInfo(Java_util_Properties p0);
	@Virtual @Overload void setHoldability(int p0);
	@Virtual @Overload void setNetworkTimeout(Java_util_concurrent_Executor p0, int p1);
	@Virtual @Overload void setReadOnly(boolean p0);
	@Virtual @Overload Java_sql_Savepoint setSavepoint();
	@Virtual @Overload Java_sql_Savepoint setSavepoint(String p0);
	@Virtual @Overload void setSchema(String p0);
	@Virtual @Overload void setTransactionIsolation(int p0);
	@Virtual @Overload void setTypeMap(Java_util_Map p0);
}

/* class java.sql.DataTruncation */
class Java_sql_DataTruncation extends Java_sql_SQLWarning {
	/*-- Method --*/
	@Virtual @Overload int getDataSize();
	@Virtual @Overload int getIndex();
	@Virtual @Overload boolean getParameter();
	@Virtual @Overload boolean getRead();
	@Virtual @Overload int getTransferSize();
}
@Overload Java_sql_DataTruncation Java_sql_DataTruncation.new(int p0, boolean p1, boolean p2, int p3, int p4);
@Overload Java_sql_DataTruncation Java_sql_DataTruncation.new(int p0, boolean p1, boolean p2, int p3, int p4, Java_lang_Throwable p5);

/* interface java.sql.DatabaseMetaData */
class Java_sql_DatabaseMetaData {
	// implements java.sql.Wrapper
	/*-- Method --*/
	@Virtual @Overload boolean allProceduresAreCallable();
	@Virtual @Overload boolean allTablesAreSelectable();
	@Virtual @Overload boolean autoCommitFailureClosesAllResultSets();
	@Virtual @Overload boolean dataDefinitionCausesTransactionCommit();
	@Virtual @Overload boolean dataDefinitionIgnoredInTransactions();
	@Virtual @Overload boolean deletesAreDetected(int p0);
	@Virtual @Overload boolean doesMaxRowSizeIncludeBlobs();
	@Virtual @Overload boolean generatedKeyAlwaysReturned();
	@Virtual @Overload Java_sql_ResultSet getAttributes(String p0, String p1, String p2, String p3);
	@Virtual @Overload Java_sql_ResultSet getBestRowIdentifier(String p0, String p1, String p2, int p3, boolean p4);
	@Virtual @Overload String getCatalogSeparator();
	@Virtual @Overload String getCatalogTerm();
	@Virtual @Overload Java_sql_ResultSet getCatalogs();
	@Virtual @Overload Java_sql_ResultSet getClientInfoProperties();
	@Virtual @Overload Java_sql_ResultSet getColumnPrivileges(String p0, String p1, String p2, String p3);
	@Virtual @Overload Java_sql_ResultSet getColumns(String p0, String p1, String p2, String p3);
	@Virtual @Overload Java_sql_Connection getConnection();
	@Virtual @Overload Java_sql_ResultSet getCrossReference(String p0, String p1, String p2, String p3, String p4, String p5);
	@Virtual @Overload int getDatabaseMajorVersion();
	@Virtual @Overload int getDatabaseMinorVersion();
	@Virtual @Overload String getDatabaseProductName();
	@Virtual @Overload String getDatabaseProductVersion();
	@Virtual @Overload int getDefaultTransactionIsolation();
	@Virtual @Overload int getDriverMajorVersion();
	@Virtual @Overload int getDriverMinorVersion();
	@Virtual @Overload String getDriverName();
	@Virtual @Overload String getDriverVersion();
	@Virtual @Overload Java_sql_ResultSet getExportedKeys(String p0, String p1, String p2);
	@Virtual @Overload String getExtraNameCharacters();
	@Virtual @Overload Java_sql_ResultSet getFunctionColumns(String p0, String p1, String p2, String p3);
	@Virtual @Overload Java_sql_ResultSet getFunctions(String p0, String p1, String p2);
	@Virtual @Overload String getIdentifierQuoteString();
	@Virtual @Overload Java_sql_ResultSet getImportedKeys(String p0, String p1, String p2);
	@Virtual @Overload Java_sql_ResultSet getIndexInfo(String p0, String p1, String p2, boolean p3, boolean p4);
	@Virtual @Overload int getJDBCMajorVersion();
	@Virtual @Overload int getJDBCMinorVersion();
	@Virtual @Overload int getMaxBinaryLiteralLength();
	@Virtual @Overload int getMaxCatalogNameLength();
	@Virtual @Overload int getMaxCharLiteralLength();
	@Virtual @Overload int getMaxColumnNameLength();
	@Virtual @Overload int getMaxColumnsInGroupBy();
	@Virtual @Overload int getMaxColumnsInIndex();
	@Virtual @Overload int getMaxColumnsInOrderBy();
	@Virtual @Overload int getMaxColumnsInSelect();
	@Virtual @Overload int getMaxColumnsInTable();
	@Virtual @Overload int getMaxConnections();
	@Virtual @Overload int getMaxCursorNameLength();
	@Virtual @Overload int getMaxIndexLength();
	@Virtual @Overload int getMaxProcedureNameLength();
	@Virtual @Overload int getMaxRowSize();
	@Virtual @Overload int getMaxSchemaNameLength();
	@Virtual @Overload int getMaxStatementLength();
	@Virtual @Overload int getMaxStatements();
	@Virtual @Overload int getMaxTableNameLength();
	@Virtual @Overload int getMaxTablesInSelect();
	@Virtual @Overload int getMaxUserNameLength();
	@Virtual @Overload String getNumericFunctions();
	@Virtual @Overload Java_sql_ResultSet getPrimaryKeys(String p0, String p1, String p2);
	@Virtual @Overload Java_sql_ResultSet getProcedureColumns(String p0, String p1, String p2, String p3);
	@Virtual @Overload String getProcedureTerm();
	@Virtual @Overload Java_sql_ResultSet getProcedures(String p0, String p1, String p2);
	@Virtual @Overload Java_sql_ResultSet getPseudoColumns(String p0, String p1, String p2, String p3);
	@Virtual @Overload int getResultSetHoldability();
	@Virtual @Overload Java_sql_RowIdLifetime getRowIdLifetime();
	@Virtual @Overload String getSQLKeywords();
	@Virtual @Overload int getSQLStateType();
	@Virtual @Overload String getSchemaTerm();
	@Virtual @Overload Java_sql_ResultSet getSchemas();
	@Virtual @Overload Java_sql_ResultSet getSchemas(String p0, String p1);
	@Virtual @Overload String getSearchStringEscape();
	@Virtual @Overload String getStringFunctions();
	@Virtual @Overload Java_sql_ResultSet getSuperTables(String p0, String p1, String p2);
	@Virtual @Overload Java_sql_ResultSet getSuperTypes(String p0, String p1, String p2);
	@Virtual @Overload String getSystemFunctions();
	@Virtual @Overload Java_sql_ResultSet getTablePrivileges(String p0, String p1, String p2);
	@Virtual @Overload Java_sql_ResultSet getTableTypes();
	@Virtual @Overload Java_sql_ResultSet getTables(String p0, String p1, String p2, String[] p3);
	@Virtual @Overload String getTimeDateFunctions();
	@Virtual @Overload Java_sql_ResultSet getTypeInfo();
	@Virtual @Overload Java_sql_ResultSet getUDTs(String p0, String p1, String p2, int[] p3);
	@Virtual @Overload String getURL();
	@Virtual @Overload String getUserName();
	@Virtual @Overload Java_sql_ResultSet getVersionColumns(String p0, String p1, String p2);
	@Virtual @Overload boolean insertsAreDetected(int p0);
	@Virtual @Overload boolean isCatalogAtStart();
	@Virtual @Overload boolean isReadOnly();
	@Virtual @Overload boolean locatorsUpdateCopy();
	@Virtual @Overload boolean nullPlusNonNullIsNull();
	@Virtual @Overload boolean nullsAreSortedAtEnd();
	@Virtual @Overload boolean nullsAreSortedAtStart();
	@Virtual @Overload boolean nullsAreSortedHigh();
	@Virtual @Overload boolean nullsAreSortedLow();
	@Virtual @Overload boolean othersDeletesAreVisible(int p0);
	@Virtual @Overload boolean othersInsertsAreVisible(int p0);
	@Virtual @Overload boolean othersUpdatesAreVisible(int p0);
	@Virtual @Overload boolean ownDeletesAreVisible(int p0);
	@Virtual @Overload boolean ownInsertsAreVisible(int p0);
	@Virtual @Overload boolean ownUpdatesAreVisible(int p0);
	@Virtual @Overload boolean storesLowerCaseIdentifiers();
	@Virtual @Overload boolean storesLowerCaseQuotedIdentifiers();
	@Virtual @Overload boolean storesMixedCaseIdentifiers();
	@Virtual @Overload boolean storesMixedCaseQuotedIdentifiers();
	@Virtual @Overload boolean storesUpperCaseIdentifiers();
	@Virtual @Overload boolean storesUpperCaseQuotedIdentifiers();
	@Virtual @Overload boolean supportsANSI92EntryLevelSQL();
	@Virtual @Overload boolean supportsANSI92FullSQL();
	@Virtual @Overload boolean supportsANSI92IntermediateSQL();
	@Virtual @Overload boolean supportsAlterTableWithAddColumn();
	@Virtual @Overload boolean supportsAlterTableWithDropColumn();
	@Virtual @Overload boolean supportsBatchUpdates();
	@Virtual @Overload boolean supportsCatalogsInDataManipulation();
	@Virtual @Overload boolean supportsCatalogsInIndexDefinitions();
	@Virtual @Overload boolean supportsCatalogsInPrivilegeDefinitions();
	@Virtual @Overload boolean supportsCatalogsInProcedureCalls();
	@Virtual @Overload boolean supportsCatalogsInTableDefinitions();
	@Virtual @Overload boolean supportsColumnAliasing();
	@Virtual @Overload boolean supportsConvert();
	@Virtual @Overload boolean supportsConvert(int p0, int p1);
	@Virtual @Overload boolean supportsCoreSQLGrammar();
	@Virtual @Overload boolean supportsCorrelatedSubqueries();
	@Virtual @Overload boolean supportsDataDefinitionAndDataManipulationTransactions();
	@Virtual @Overload boolean supportsDataManipulationTransactionsOnly();
	@Virtual @Overload boolean supportsDifferentTableCorrelationNames();
	@Virtual @Overload boolean supportsExpressionsInOrderBy();
	@Virtual @Overload boolean supportsExtendedSQLGrammar();
	@Virtual @Overload boolean supportsFullOuterJoins();
	@Virtual @Overload boolean supportsGetGeneratedKeys();
	@Virtual @Overload boolean supportsGroupBy();
	@Virtual @Overload boolean supportsGroupByBeyondSelect();
	@Virtual @Overload boolean supportsGroupByUnrelated();
	@Virtual @Overload boolean supportsIntegrityEnhancementFacility();
	@Virtual @Overload boolean supportsLikeEscapeClause();
	@Virtual @Overload boolean supportsLimitedOuterJoins();
	@Virtual @Overload boolean supportsMinimumSQLGrammar();
	@Virtual @Overload boolean supportsMixedCaseIdentifiers();
	@Virtual @Overload boolean supportsMixedCaseQuotedIdentifiers();
	@Virtual @Overload boolean supportsMultipleOpenResults();
	@Virtual @Overload boolean supportsMultipleResultSets();
	@Virtual @Overload boolean supportsMultipleTransactions();
	@Virtual @Overload boolean supportsNamedParameters();
	@Virtual @Overload boolean supportsNonNullableColumns();
	@Virtual @Overload boolean supportsOpenCursorsAcrossCommit();
	@Virtual @Overload boolean supportsOpenCursorsAcrossRollback();
	@Virtual @Overload boolean supportsOpenStatementsAcrossCommit();
	@Virtual @Overload boolean supportsOpenStatementsAcrossRollback();
	@Virtual @Overload boolean supportsOrderByUnrelated();
	@Virtual @Overload boolean supportsOuterJoins();
	@Virtual @Overload boolean supportsPositionedDelete();
	@Virtual @Overload boolean supportsPositionedUpdate();
	@Virtual @Overload boolean supportsResultSetConcurrency(int p0, int p1);
	@Virtual @Overload boolean supportsResultSetHoldability(int p0);
	@Virtual @Overload boolean supportsResultSetType(int p0);
	@Virtual @Overload boolean supportsSavepoints();
	@Virtual @Overload boolean supportsSchemasInDataManipulation();
	@Virtual @Overload boolean supportsSchemasInIndexDefinitions();
	@Virtual @Overload boolean supportsSchemasInPrivilegeDefinitions();
	@Virtual @Overload boolean supportsSchemasInProcedureCalls();
	@Virtual @Overload boolean supportsSchemasInTableDefinitions();
	@Virtual @Overload boolean supportsSelectForUpdate();
	@Virtual @Overload boolean supportsStatementPooling();
	@Virtual @Overload boolean supportsStoredFunctionsUsingCallSyntax();
	@Virtual @Overload boolean supportsStoredProcedures();
	@Virtual @Overload boolean supportsSubqueriesInComparisons();
	@Virtual @Overload boolean supportsSubqueriesInExists();
	@Virtual @Overload boolean supportsSubqueriesInIns();
	@Virtual @Overload boolean supportsSubqueriesInQuantifieds();
	@Virtual @Overload boolean supportsTableCorrelationNames();
	@Virtual @Overload boolean supportsTransactionIsolationLevel(int p0);
	@Virtual @Overload boolean supportsTransactions();
	@Virtual @Overload boolean supportsUnion();
	@Virtual @Overload boolean supportsUnionAll();
	@Virtual @Overload boolean updatesAreDetected(int p0);
	@Virtual @Overload boolean usesLocalFilePerTable();
	@Virtual @Overload boolean usesLocalFiles();
}

/* class java.sql.Date */
class Java_sql_Date extends Java_util_Date {
	/*-- Method --*/
	@Virtual @Overload Java_sql_Date valueOf(String p0);
}
@Overload Java_sql_Date Java_sql_Date.new(int p0, int p1, int p2);
@Overload Java_sql_Date Java_sql_Date.new(long p0);

/* interface java.sql.Driver */
class Java_sql_Driver {
	/*-- Method --*/
	@Virtual @Overload boolean acceptsURL(String p0);
	@Virtual @Overload Java_sql_Connection connect(String p0, Java_util_Properties p1);
	@Virtual @Overload int getMajorVersion();
	@Virtual @Overload int getMinorVersion();
	@Virtual @Overload Java_util_logging_Logger getParentLogger();
	@Virtual @Overload Java_sql_DriverPropertyInfo[] getPropertyInfo(String p0, Java_util_Properties p1);
	@Virtual @Overload boolean jdbcCompliant();
}

/* class java.sql.DriverManager */
class Java_sql_DriverManager {
	/*-- Method --*/
	@Virtual @Overload void deregisterDriver(Java_sql_Driver p0);
	@Virtual @Overload Java_sql_Connection getConnection(String p0, Java_util_Properties p1);
	@Virtual @Overload Java_sql_Connection getConnection(String p0, String p1, String p2);
	@Virtual @Overload Java_sql_Connection getConnection(String p0);
	@Virtual @Overload Java_sql_Driver getDriver(String p0);
	@Virtual @Overload Java_util_Enumeration getDrivers();
	@Virtual @Overload Java_io_PrintStream getLogStream();
	@Virtual @Overload Java_io_PrintWriter getLogWriter();
	@Virtual @Overload int getLoginTimeout();
	@Virtual @Overload void println(String p0);
	@Virtual @Overload void registerDriver(Java_sql_Driver p0);
	@Virtual @Overload void setLogStream(Java_io_PrintStream p0);
	@Virtual @Overload void setLogWriter(Java_io_PrintWriter p0);
	@Virtual @Overload void setLoginTimeout(int p0);
}

/* class java.sql.DriverPropertyInfo */
class Java_sql_DriverPropertyInfo {
}
Java_sql_DriverPropertyInfo Java_sql_DriverPropertyInfo.new(String p0, String p1);

/* interface java.sql.NClob */
class Java_sql_NClob {
	// implements java.sql.Clob
}

/* interface java.sql.ParameterMetaData */
class Java_sql_ParameterMetaData {
	// implements java.sql.Wrapper
	/*-- Method --*/
	@Virtual @Overload String getParameterClassName(int p0);
	@Virtual @Overload int getParameterCount();
	@Virtual @Overload int getParameterMode(int p0);
	@Virtual @Overload int getParameterType(int p0);
	@Virtual @Overload String getParameterTypeName(int p0);
	@Virtual @Overload int getPrecision(int p0);
	@Virtual @Overload int getScale(int p0);
	@Virtual @Overload int isNullable(int p0);
	@Virtual @Overload boolean isSigned(int p0);
}

/* interface java.sql.PreparedStatement */
class Java_sql_PreparedStatement {
	// implements java.sql.Statement
	/*-- Method --*/
	@Virtual @Overload void addBatch();
	@Virtual @Overload void clearParameters();
	@Virtual @Overload boolean execute();
	@Virtual @Overload Java_sql_ResultSet executeQuery();
	@Virtual @Overload int executeUpdate();
	@Virtual @Overload Java_sql_ResultSetMetaData getMetaData();
	@Virtual @Overload Java_sql_ParameterMetaData getParameterMetaData();
	@Virtual @Overload void setArray(int p0, Java_sql_Array p1);
	@Virtual @Overload void setAsciiStream(int p0, Java_io_InputStream p1, int p2);
	@Virtual @Overload void setAsciiStream(int p0, Java_io_InputStream p1, long p2);
	@Virtual @Overload void setAsciiStream(int p0, Java_io_InputStream p1);
	@Virtual @Overload void setBigDecimal(int p0, Java_math_BigDecimal p1);
	@Virtual @Overload void setBinaryStream(int p0, Java_io_InputStream p1, int p2);
	@Virtual @Overload void setBinaryStream(int p0, Java_io_InputStream p1, long p2);
	@Virtual @Overload void setBinaryStream(int p0, Java_io_InputStream p1);
	@Virtual @Overload void setBlob(int p0, Java_sql_Blob p1);
	@Virtual @Overload void setBlob(int p0, Java_io_InputStream p1, long p2);
	@Virtual @Overload void setBlob(int p0, Java_io_InputStream p1);
	@Virtual @Overload void setBoolean(int p0, boolean p1);
	@Virtual @Overload void setByte(int p0, int p1);
	@Virtual @Overload void setBytes(int p0, int[] p1);
	@Virtual @Overload void setCharacterStream(int p0, Java_io_Reader p1, int p2);
	@Virtual @Overload void setCharacterStream(int p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void setCharacterStream(int p0, Java_io_Reader p1);
	@Virtual @Overload void setClob(int p0, Java_sql_Clob p1);
	@Virtual @Overload void setClob(int p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void setClob(int p0, Java_io_Reader p1);
	@Virtual @Overload void setDate(int p0, Java_sql_Date p1);
	@Virtual @Overload void setDate(int p0, Java_sql_Date p1, Java_util_Calendar p2);
	@Virtual @Overload void setDouble(int p0, double p1);
	@Virtual @Overload void setFloat(int p0, float p1);
	@Virtual @Overload void setInt(int p0, int p1);
	@Virtual @Overload void setLong(int p0, long p1);
	@Virtual @Overload void setNCharacterStream(int p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void setNCharacterStream(int p0, Java_io_Reader p1);
	@Virtual @Overload void setNClob(int p0, Java_sql_NClob p1);
	@Virtual @Overload void setNClob(int p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void setNClob(int p0, Java_io_Reader p1);
	@Virtual @Overload void setNString(int p0, String p1);
	@Virtual @Overload void setNull(int p0, int p1);
	@Virtual @Overload void setNull(int p0, int p1, String p2);
	@Virtual @Overload void setObject(int p0, Object p1, int p2);
	@Virtual @Overload void setObject(int p0, Object p1);
	@Virtual @Overload void setObject(int p0, Object p1, int p2, int p3);
	@Virtual @Overload void setRef(int p0, Java_sql_Ref p1);
	@Virtual @Overload void setRowId(int p0, Java_sql_RowId p1);
	@Virtual @Overload void setSQLXML(int p0, Java_sql_SQLXML p1);
	@Virtual @Overload void setShort(int p0, int p1);
	@Virtual @Overload void setString(int p0, String p1);
	@Virtual @Overload void setTime(int p0, Java_sql_Time p1);
	@Virtual @Overload void setTime(int p0, Java_sql_Time p1, Java_util_Calendar p2);
	@Virtual @Overload void setTimestamp(int p0, Java_sql_Timestamp p1);
	@Virtual @Overload void setTimestamp(int p0, Java_sql_Timestamp p1, Java_util_Calendar p2);
	@Virtual @Overload void setURL(int p0, Java_net_URL p1);
	@Virtual @Overload void setUnicodeStream(int p0, Java_io_InputStream p1, int p2);
}

/* class java.sql.PseudoColumnUsage */
class Java_sql_PseudoColumnUsage extends Java_lang_Enum {
	/*-- Method --*/
	@Virtual @Overload Java_sql_PseudoColumnUsage valueOf(String p0);
	@Virtual @Overload Java_sql_PseudoColumnUsage[] values();
}

/* interface java.sql.Ref */
class Java_sql_Ref {
	/*-- Method --*/
	@Virtual @Overload String getBaseTypeName();
	@Virtual @Overload Object getObject(Java_util_Map p0);
	@Virtual @Overload Object getObject();
	@Virtual @Overload void setObject(Object p0);
}

/* interface java.sql.ResultSet */
class Java_sql_ResultSet {
	// implements java.sql.Wrapper, java.lang.AutoCloseable
	/*-- Method --*/
	@Virtual @Overload boolean absolute(int p0);
	@Virtual @Overload void afterLast();
	@Virtual @Overload void beforeFirst();
	@Virtual @Overload void cancelRowUpdates();
	@Virtual @Overload void clearWarnings();
	@Virtual @Overload void close();
	@Virtual @Overload void deleteRow();
	@Virtual @Overload int findColumn(String p0);
	@Virtual @Overload boolean first();
	@Virtual @Overload Java_sql_Array getArray(int p0);
	@Virtual @Overload Java_sql_Array getArray(String p0);
	@Virtual @Overload Java_io_InputStream getAsciiStream(int p0);
	@Virtual @Overload Java_io_InputStream getAsciiStream(String p0);
	@Virtual @Overload Java_math_BigDecimal getBigDecimal(int p0, int p1);
	@Virtual @Overload Java_math_BigDecimal getBigDecimal(String p0, int p1);
	@Virtual @Overload Java_math_BigDecimal getBigDecimal(int p0);
	@Virtual @Overload Java_math_BigDecimal getBigDecimal(String p0);
	@Virtual @Overload Java_io_InputStream getBinaryStream(int p0);
	@Virtual @Overload Java_io_InputStream getBinaryStream(String p0);
	@Virtual @Overload Java_sql_Blob getBlob(int p0);
	@Virtual @Overload Java_sql_Blob getBlob(String p0);
	@Virtual @Overload boolean getBoolean(int p0);
	@Virtual @Overload boolean getBoolean(String p0);
	@Virtual @Overload int getByte(int p0);
	@Virtual @Overload int getByte(String p0);
	@Virtual @Overload int[] getBytes(int p0);
	@Virtual @Overload int[] getBytes(String p0);
	@Virtual @Overload Java_io_Reader getCharacterStream(int p0);
	@Virtual @Overload Java_io_Reader getCharacterStream(String p0);
	@Virtual @Overload Java_sql_Clob getClob(int p0);
	@Virtual @Overload Java_sql_Clob getClob(String p0);
	@Virtual @Overload int getConcurrency();
	@Virtual @Overload String getCursorName();
	@Virtual @Overload Java_sql_Date getDate(int p0);
	@Virtual @Overload Java_sql_Date getDate(String p0);
	@Virtual @Overload Java_sql_Date getDate(int p0, Java_util_Calendar p1);
	@Virtual @Overload Java_sql_Date getDate(String p0, Java_util_Calendar p1);
	@Virtual @Overload double getDouble(int p0);
	@Virtual @Overload double getDouble(String p0);
	@Virtual @Overload int getFetchDirection();
	@Virtual @Overload int getFetchSize();
	@Virtual @Overload float getFloat(int p0);
	@Virtual @Overload float getFloat(String p0);
	@Virtual @Overload int getHoldability();
	@Virtual @Overload int getInt(int p0);
	@Virtual @Overload int getInt(String p0);
	@Virtual @Overload long getLong(int p0);
	@Virtual @Overload long getLong(String p0);
	@Virtual @Overload Java_sql_ResultSetMetaData getMetaData();
	@Virtual @Overload Java_io_Reader getNCharacterStream(int p0);
	@Virtual @Overload Java_io_Reader getNCharacterStream(String p0);
	@Virtual @Overload Java_sql_NClob getNClob(int p0);
	@Virtual @Overload Java_sql_NClob getNClob(String p0);
	@Virtual @Overload String getNString(int p0);
	@Virtual @Overload String getNString(String p0);
	@Virtual @Overload Object getObject(int p0);
	@Virtual @Overload Object getObject(String p0);
	@Virtual @Overload Object getObject(int p0, Java_util_Map p1);
	@Virtual @Overload Object getObject(String p0, Java_util_Map p1);
	@Virtual @Overload Object getObject(int p0, Class p1);
	@Virtual @Overload Object getObject(String p0, Class p1);
	@Virtual @Overload Java_sql_Ref getRef(int p0);
	@Virtual @Overload Java_sql_Ref getRef(String p0);
	@Virtual @Overload int getRow();
	@Virtual @Overload Java_sql_RowId getRowId(int p0);
	@Virtual @Overload Java_sql_RowId getRowId(String p0);
	@Virtual @Overload Java_sql_SQLXML getSQLXML(int p0);
	@Virtual @Overload Java_sql_SQLXML getSQLXML(String p0);
	@Virtual @Overload int getShort(int p0);
	@Virtual @Overload int getShort(String p0);
	@Virtual @Overload Java_sql_Statement getStatement();
	@Virtual @Overload String getString(int p0);
	@Virtual @Overload String getString(String p0);
	@Virtual @Overload Java_sql_Time getTime(int p0);
	@Virtual @Overload Java_sql_Time getTime(String p0);
	@Virtual @Overload Java_sql_Time getTime(int p0, Java_util_Calendar p1);
	@Virtual @Overload Java_sql_Time getTime(String p0, Java_util_Calendar p1);
	@Virtual @Overload Java_sql_Timestamp getTimestamp(int p0);
	@Virtual @Overload Java_sql_Timestamp getTimestamp(String p0);
	@Virtual @Overload Java_sql_Timestamp getTimestamp(int p0, Java_util_Calendar p1);
	@Virtual @Overload Java_sql_Timestamp getTimestamp(String p0, Java_util_Calendar p1);
	@Virtual @Overload int getType();
	@Virtual @Overload Java_net_URL getURL(int p0);
	@Virtual @Overload Java_net_URL getURL(String p0);
	@Virtual @Overload Java_io_InputStream getUnicodeStream(int p0);
	@Virtual @Overload Java_io_InputStream getUnicodeStream(String p0);
	@Virtual @Overload Java_sql_SQLWarning getWarnings();
	@Virtual @Overload void insertRow();
	@Virtual @Overload boolean isAfterLast();
	@Virtual @Overload boolean isBeforeFirst();
	@Virtual @Overload boolean isClosed();
	@Virtual @Overload boolean isFirst();
	@Virtual @Overload boolean isLast();
	@Virtual @Overload boolean last();
	@Virtual @Overload void moveToCurrentRow();
	@Virtual @Overload void moveToInsertRow();
	@Virtual @Overload boolean next();
	@Virtual @Overload boolean previous();
	@Virtual @Overload void refreshRow();
	@Virtual @Overload boolean relative(int p0);
	@Virtual @Overload boolean rowDeleted();
	@Virtual @Overload boolean rowInserted();
	@Virtual @Overload boolean rowUpdated();
	@Virtual @Overload void setFetchDirection(int p0);
	@Virtual @Overload void setFetchSize(int p0);
	@Virtual @Overload void updateArray(int p0, Java_sql_Array p1);
	@Virtual @Overload void updateArray(String p0, Java_sql_Array p1);
	@Virtual @Overload void updateAsciiStream(int p0, Java_io_InputStream p1, int p2);
	@Virtual @Overload void updateAsciiStream(String p0, Java_io_InputStream p1, int p2);
	@Virtual @Overload void updateAsciiStream(int p0, Java_io_InputStream p1, long p2);
	@Virtual @Overload void updateAsciiStream(String p0, Java_io_InputStream p1, long p2);
	@Virtual @Overload void updateAsciiStream(int p0, Java_io_InputStream p1);
	@Virtual @Overload void updateAsciiStream(String p0, Java_io_InputStream p1);
	@Virtual @Overload void updateBigDecimal(int p0, Java_math_BigDecimal p1);
	@Virtual @Overload void updateBigDecimal(String p0, Java_math_BigDecimal p1);
	@Virtual @Overload void updateBinaryStream(int p0, Java_io_InputStream p1, int p2);
	@Virtual @Overload void updateBinaryStream(String p0, Java_io_InputStream p1, int p2);
	@Virtual @Overload void updateBinaryStream(int p0, Java_io_InputStream p1, long p2);
	@Virtual @Overload void updateBinaryStream(String p0, Java_io_InputStream p1, long p2);
	@Virtual @Overload void updateBinaryStream(int p0, Java_io_InputStream p1);
	@Virtual @Overload void updateBinaryStream(String p0, Java_io_InputStream p1);
	@Virtual @Overload void updateBlob(int p0, Java_sql_Blob p1);
	@Virtual @Overload void updateBlob(String p0, Java_sql_Blob p1);
	@Virtual @Overload void updateBlob(int p0, Java_io_InputStream p1, long p2);
	@Virtual @Overload void updateBlob(String p0, Java_io_InputStream p1, long p2);
	@Virtual @Overload void updateBlob(int p0, Java_io_InputStream p1);
	@Virtual @Overload void updateBlob(String p0, Java_io_InputStream p1);
	@Virtual @Overload void updateBoolean(int p0, boolean p1);
	@Virtual @Overload void updateBoolean(String p0, boolean p1);
	@Virtual @Overload void updateByte(int p0, int p1);
	@Virtual @Overload void updateByte(String p0, int p1);
	@Virtual @Overload void updateBytes(int p0, int[] p1);
	@Virtual @Overload void updateBytes(String p0, int[] p1);
	@Virtual @Overload void updateCharacterStream(int p0, Java_io_Reader p1, int p2);
	@Virtual @Overload void updateCharacterStream(String p0, Java_io_Reader p1, int p2);
	@Virtual @Overload void updateCharacterStream(int p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void updateCharacterStream(String p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void updateCharacterStream(int p0, Java_io_Reader p1);
	@Virtual @Overload void updateCharacterStream(String p0, Java_io_Reader p1);
	@Virtual @Overload void updateClob(int p0, Java_sql_Clob p1);
	@Virtual @Overload void updateClob(String p0, Java_sql_Clob p1);
	@Virtual @Overload void updateClob(int p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void updateClob(String p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void updateClob(int p0, Java_io_Reader p1);
	@Virtual @Overload void updateClob(String p0, Java_io_Reader p1);
	@Virtual @Overload void updateDate(int p0, Java_sql_Date p1);
	@Virtual @Overload void updateDate(String p0, Java_sql_Date p1);
	@Virtual @Overload void updateDouble(int p0, double p1);
	@Virtual @Overload void updateDouble(String p0, double p1);
	@Virtual @Overload void updateFloat(int p0, float p1);
	@Virtual @Overload void updateFloat(String p0, float p1);
	@Virtual @Overload void updateInt(int p0, int p1);
	@Virtual @Overload void updateInt(String p0, int p1);
	@Virtual @Overload void updateLong(int p0, long p1);
	@Virtual @Overload void updateLong(String p0, long p1);
	@Virtual @Overload void updateNCharacterStream(int p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void updateNCharacterStream(String p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void updateNCharacterStream(int p0, Java_io_Reader p1);
	@Virtual @Overload void updateNCharacterStream(String p0, Java_io_Reader p1);
	@Virtual @Overload void updateNClob(int p0, Java_sql_NClob p1);
	@Virtual @Overload void updateNClob(String p0, Java_sql_NClob p1);
	@Virtual @Overload void updateNClob(int p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void updateNClob(String p0, Java_io_Reader p1, long p2);
	@Virtual @Overload void updateNClob(int p0, Java_io_Reader p1);
	@Virtual @Overload void updateNClob(String p0, Java_io_Reader p1);
	@Virtual @Overload void updateNString(int p0, String p1);
	@Virtual @Overload void updateNString(String p0, String p1);
	@Virtual @Overload void updateNull(int p0);
	@Virtual @Overload void updateNull(String p0);
	@Virtual @Overload void updateObject(int p0, Object p1, int p2);
	@Virtual @Overload void updateObject(int p0, Object p1);
	@Virtual @Overload void updateObject(String p0, Object p1, int p2);
	@Virtual @Overload void updateObject(String p0, Object p1);
	@Virtual @Overload void updateRef(int p0, Java_sql_Ref p1);
	@Virtual @Overload void updateRef(String p0, Java_sql_Ref p1);
	@Virtual @Overload void updateRow();
	@Virtual @Overload void updateRowId(int p0, Java_sql_RowId p1);
	@Virtual @Overload void updateRowId(String p0, Java_sql_RowId p1);
	@Virtual @Overload void updateSQLXML(int p0, Java_sql_SQLXML p1);
	@Virtual @Overload void updateSQLXML(String p0, Java_sql_SQLXML p1);
	@Virtual @Overload void updateShort(int p0, int p1);
	@Virtual @Overload void updateShort(String p0, int p1);
	@Virtual @Overload void updateString(int p0, String p1);
	@Virtual @Overload void updateString(String p0, String p1);
	@Virtual @Overload void updateTime(int p0, Java_sql_Time p1);
	@Virtual @Overload void updateTime(String p0, Java_sql_Time p1);
	@Virtual @Overload void updateTimestamp(int p0, Java_sql_Timestamp p1);
	@Virtual @Overload void updateTimestamp(String p0, Java_sql_Timestamp p1);
	@Virtual @Overload boolean wasNull();
}

/* interface java.sql.ResultSetMetaData */
class Java_sql_ResultSetMetaData {
	// implements java.sql.Wrapper
	/*-- Method --*/
	@Virtual @Overload String getCatalogName(int p0);
	@Virtual @Overload String getColumnClassName(int p0);
	@Virtual @Overload int getColumnCount();
	@Virtual @Overload int getColumnDisplaySize(int p0);
	@Virtual @Overload String getColumnLabel(int p0);
	@Virtual @Overload String getColumnName(int p0);
	@Virtual @Overload int getColumnType(int p0);
	@Virtual @Overload String getColumnTypeName(int p0);
	@Virtual @Overload int getPrecision(int p0);
	@Virtual @Overload int getScale(int p0);
	@Virtual @Overload String getSchemaName(int p0);
	@Virtual @Overload String getTableName(int p0);
	@Virtual @Overload boolean isAutoIncrement(int p0);
	@Virtual @Overload boolean isCaseSensitive(int p0);
	@Virtual @Overload boolean isCurrency(int p0);
	@Virtual @Overload boolean isDefinitelyWritable(int p0);
	@Virtual @Overload int isNullable(int p0);
	@Virtual @Overload boolean isReadOnly(int p0);
	@Virtual @Overload boolean isSearchable(int p0);
	@Virtual @Overload boolean isSigned(int p0);
	@Virtual @Overload boolean isWritable(int p0);
}

/* interface java.sql.RowId */
class Java_sql_RowId {
	/*-- Method --*/
	@Virtual @Overload boolean equals(Object p0);
	@Virtual @Overload int[] getBytes();
	//@Virtual @Overload int hashCode();
	@Virtual @Overload String toString();
}

/* class java.sql.RowIdLifetime */
class Java_sql_RowIdLifetime extends Java_lang_Enum {
	/*-- Method --*/
	@Virtual @Overload Java_sql_RowIdLifetime valueOf(String p0);
	@Virtual @Overload Java_sql_RowIdLifetime[] values();
}

/* class java.sql.SQLClientInfoException */
class Java_sql_SQLClientInfoException extends Java_sql_SQLException {
	/*-- Method --*/
	@Virtual @Overload Java_util_Map getFailedProperties();
}
@Overload Java_sql_SQLClientInfoException Java_sql_SQLClientInfoException.new();
@Overload Java_sql_SQLClientInfoException Java_sql_SQLClientInfoException.new(Java_util_Map p0);
@Overload Java_sql_SQLClientInfoException Java_sql_SQLClientInfoException.new(Java_util_Map p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLClientInfoException Java_sql_SQLClientInfoException.new(String p0, Java_util_Map p1);
@Overload Java_sql_SQLClientInfoException Java_sql_SQLClientInfoException.new(String p0, Java_util_Map p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLClientInfoException Java_sql_SQLClientInfoException.new(String p0, String p1, Java_util_Map p2);
@Overload Java_sql_SQLClientInfoException Java_sql_SQLClientInfoException.new(String p0, String p1, Java_util_Map p2, Java_lang_Throwable p3);
@Overload Java_sql_SQLClientInfoException Java_sql_SQLClientInfoException.new(String p0, String p1, int p2, Java_util_Map p3);
@Overload Java_sql_SQLClientInfoException Java_sql_SQLClientInfoException.new(String p0, String p1, int p2, Java_util_Map p3, Java_lang_Throwable p4);

/* interface java.sql.SQLData */
class Java_sql_SQLData {
	/*-- Method --*/
	@Virtual @Overload String getSQLTypeName();
	@Virtual @Overload void readSQL(Java_sql_SQLInput p0, String p1);
	@Virtual @Overload void writeSQL(Java_sql_SQLOutput p0);
}

/* class java.sql.SQLDataException */
class Java_sql_SQLDataException extends Java_sql_SQLNonTransientException {
}
@Overload Java_sql_SQLDataException Java_sql_SQLDataException.new();
@Overload Java_sql_SQLDataException Java_sql_SQLDataException.new(String p0);
@Overload Java_sql_SQLDataException Java_sql_SQLDataException.new(String p0, String p1);
@Overload Java_sql_SQLDataException Java_sql_SQLDataException.new(String p0, String p1, int p2);
@Overload Java_sql_SQLDataException Java_sql_SQLDataException.new(Java_lang_Throwable p0);
@Overload Java_sql_SQLDataException Java_sql_SQLDataException.new(String p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLDataException Java_sql_SQLDataException.new(String p0, String p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLDataException Java_sql_SQLDataException.new(String p0, String p1, int p2, Java_lang_Throwable p3);

/* class java.sql.SQLException */
class Java_sql_SQLException extends Java_lang_Exception {
	// implements java.lang.Iterable
	/*-- Method --*/
	@Virtual @Overload int getErrorCode();
	@Virtual @Overload Java_sql_SQLException getNextException();
	@Virtual @Overload String getSQLState();
	@Virtual @Overload Java_util_Iterator iterator();
	@Virtual @Overload void setNextException(Java_sql_SQLException p0);
}
@Overload Java_sql_SQLException Java_sql_SQLException.new(String p0, String p1, int p2);
@Overload Java_sql_SQLException Java_sql_SQLException.new(String p0, String p1);
@Overload Java_sql_SQLException Java_sql_SQLException.new(String p0);
@Overload Java_sql_SQLException Java_sql_SQLException.new();
@Overload Java_sql_SQLException Java_sql_SQLException.new(Java_lang_Throwable p0);
@Overload Java_sql_SQLException Java_sql_SQLException.new(String p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLException Java_sql_SQLException.new(String p0, String p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLException Java_sql_SQLException.new(String p0, String p1, int p2, Java_lang_Throwable p3);

/* class java.sql.SQLFeatureNotSupportedException */
class Java_sql_SQLFeatureNotSupportedException extends Java_sql_SQLNonTransientException {
}
@Overload Java_sql_SQLFeatureNotSupportedException Java_sql_SQLFeatureNotSupportedException.new();
@Overload Java_sql_SQLFeatureNotSupportedException Java_sql_SQLFeatureNotSupportedException.new(String p0);
@Overload Java_sql_SQLFeatureNotSupportedException Java_sql_SQLFeatureNotSupportedException.new(String p0, String p1);
@Overload Java_sql_SQLFeatureNotSupportedException Java_sql_SQLFeatureNotSupportedException.new(String p0, String p1, int p2);
@Overload Java_sql_SQLFeatureNotSupportedException Java_sql_SQLFeatureNotSupportedException.new(Java_lang_Throwable p0);
@Overload Java_sql_SQLFeatureNotSupportedException Java_sql_SQLFeatureNotSupportedException.new(String p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLFeatureNotSupportedException Java_sql_SQLFeatureNotSupportedException.new(String p0, String p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLFeatureNotSupportedException Java_sql_SQLFeatureNotSupportedException.new(String p0, String p1, int p2, Java_lang_Throwable p3);

/* interface java.sql.SQLInput */
class Java_sql_SQLInput {
	/*-- Method --*/
	@Virtual @Overload Java_sql_Array readArray();
	@Virtual @Overload Java_io_InputStream readAsciiStream();
	@Virtual @Overload Java_math_BigDecimal readBigDecimal();
	@Virtual @Overload Java_io_InputStream readBinaryStream();
	@Virtual @Overload Java_sql_Blob readBlob();
	@Virtual @Overload boolean readBoolean();
	@Virtual @Overload int readByte();
	@Virtual @Overload int[] readBytes();
	@Virtual @Overload Java_io_Reader readCharacterStream();
	@Virtual @Overload Java_sql_Clob readClob();
	@Virtual @Overload Java_sql_Date readDate();
	@Virtual @Overload double readDouble();
	@Virtual @Overload float readFloat();
	@Virtual @Overload int readInt();
	@Virtual @Overload long readLong();
	@Virtual @Overload Java_sql_NClob readNClob();
	@Virtual @Overload String readNString();
	@Virtual @Overload Object readObject();
	@Virtual @Overload Java_sql_Ref readRef();
	@Virtual @Overload Java_sql_RowId readRowId();
	@Virtual @Overload Java_sql_SQLXML readSQLXML();
	@Virtual @Overload int readShort();
	@Virtual @Overload String readString();
	@Virtual @Overload Java_sql_Time readTime();
	@Virtual @Overload Java_sql_Timestamp readTimestamp();
	@Virtual @Overload Java_net_URL readURL();
	@Virtual @Overload boolean wasNull();
}

/* class java.sql.SQLIntegrityConstraintViolationException */
class Java_sql_SQLIntegrityConstraintViolationException extends Java_sql_SQLNonTransientException {
}
@Overload Java_sql_SQLIntegrityConstraintViolationException Java_sql_SQLIntegrityConstraintViolationException.new();
@Overload Java_sql_SQLIntegrityConstraintViolationException Java_sql_SQLIntegrityConstraintViolationException.new(String p0);
@Overload Java_sql_SQLIntegrityConstraintViolationException Java_sql_SQLIntegrityConstraintViolationException.new(String p0, String p1);
@Overload Java_sql_SQLIntegrityConstraintViolationException Java_sql_SQLIntegrityConstraintViolationException.new(String p0, String p1, int p2);
@Overload Java_sql_SQLIntegrityConstraintViolationException Java_sql_SQLIntegrityConstraintViolationException.new(Java_lang_Throwable p0);
@Overload Java_sql_SQLIntegrityConstraintViolationException Java_sql_SQLIntegrityConstraintViolationException.new(String p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLIntegrityConstraintViolationException Java_sql_SQLIntegrityConstraintViolationException.new(String p0, String p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLIntegrityConstraintViolationException Java_sql_SQLIntegrityConstraintViolationException.new(String p0, String p1, int p2, Java_lang_Throwable p3);

/* class java.sql.SQLInvalidAuthorizationSpecException */
class Java_sql_SQLInvalidAuthorizationSpecException extends Java_sql_SQLNonTransientException {
}
@Overload Java_sql_SQLInvalidAuthorizationSpecException Java_sql_SQLInvalidAuthorizationSpecException.new();
@Overload Java_sql_SQLInvalidAuthorizationSpecException Java_sql_SQLInvalidAuthorizationSpecException.new(String p0);
@Overload Java_sql_SQLInvalidAuthorizationSpecException Java_sql_SQLInvalidAuthorizationSpecException.new(String p0, String p1);
@Overload Java_sql_SQLInvalidAuthorizationSpecException Java_sql_SQLInvalidAuthorizationSpecException.new(String p0, String p1, int p2);
@Overload Java_sql_SQLInvalidAuthorizationSpecException Java_sql_SQLInvalidAuthorizationSpecException.new(Java_lang_Throwable p0);
@Overload Java_sql_SQLInvalidAuthorizationSpecException Java_sql_SQLInvalidAuthorizationSpecException.new(String p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLInvalidAuthorizationSpecException Java_sql_SQLInvalidAuthorizationSpecException.new(String p0, String p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLInvalidAuthorizationSpecException Java_sql_SQLInvalidAuthorizationSpecException.new(String p0, String p1, int p2, Java_lang_Throwable p3);

/* class java.sql.SQLNonTransientConnectionException */
class Java_sql_SQLNonTransientConnectionException extends Java_sql_SQLNonTransientException {
}
@Overload Java_sql_SQLNonTransientConnectionException Java_sql_SQLNonTransientConnectionException.new();
@Overload Java_sql_SQLNonTransientConnectionException Java_sql_SQLNonTransientConnectionException.new(String p0);
@Overload Java_sql_SQLNonTransientConnectionException Java_sql_SQLNonTransientConnectionException.new(String p0, String p1);
@Overload Java_sql_SQLNonTransientConnectionException Java_sql_SQLNonTransientConnectionException.new(String p0, String p1, int p2);
@Overload Java_sql_SQLNonTransientConnectionException Java_sql_SQLNonTransientConnectionException.new(Java_lang_Throwable p0);
@Overload Java_sql_SQLNonTransientConnectionException Java_sql_SQLNonTransientConnectionException.new(String p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLNonTransientConnectionException Java_sql_SQLNonTransientConnectionException.new(String p0, String p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLNonTransientConnectionException Java_sql_SQLNonTransientConnectionException.new(String p0, String p1, int p2, Java_lang_Throwable p3);

/* class java.sql.SQLNonTransientException */
class Java_sql_SQLNonTransientException extends Java_sql_SQLException {
}
@Overload Java_sql_SQLNonTransientException Java_sql_SQLNonTransientException.new();
@Overload Java_sql_SQLNonTransientException Java_sql_SQLNonTransientException.new(String p0);
@Overload Java_sql_SQLNonTransientException Java_sql_SQLNonTransientException.new(String p0, String p1);
@Overload Java_sql_SQLNonTransientException Java_sql_SQLNonTransientException.new(String p0, String p1, int p2);
@Overload Java_sql_SQLNonTransientException Java_sql_SQLNonTransientException.new(Java_lang_Throwable p0);
@Overload Java_sql_SQLNonTransientException Java_sql_SQLNonTransientException.new(String p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLNonTransientException Java_sql_SQLNonTransientException.new(String p0, String p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLNonTransientException Java_sql_SQLNonTransientException.new(String p0, String p1, int p2, Java_lang_Throwable p3);

/* interface java.sql.SQLOutput */
class Java_sql_SQLOutput {
	/*-- Method --*/
	@Virtual @Overload void writeArray(Java_sql_Array p0);
	@Virtual @Overload void writeAsciiStream(Java_io_InputStream p0);
	@Virtual @Overload void writeBigDecimal(Java_math_BigDecimal p0);
	@Virtual @Overload void writeBinaryStream(Java_io_InputStream p0);
	@Virtual @Overload void writeBlob(Java_sql_Blob p0);
	@Virtual @Overload void writeBoolean(boolean p0);
	@Virtual @Overload void writeByte(int p0);
	@Virtual @Overload void writeBytes(int[] p0);
	@Virtual @Overload void writeCharacterStream(Java_io_Reader p0);
	@Virtual @Overload void writeClob(Java_sql_Clob p0);
	@Virtual @Overload void writeDate(Java_sql_Date p0);
	@Virtual @Overload void writeDouble(double p0);
	@Virtual @Overload void writeFloat(float p0);
	@Virtual @Overload void writeInt(int p0);
	@Virtual @Overload void writeLong(long p0);
	@Virtual @Overload void writeNClob(Java_sql_NClob p0);
	@Virtual @Overload void writeNString(String p0);
	@Virtual @Overload void writeObject(Java_sql_SQLData p0);
	@Virtual @Overload void writeRef(Java_sql_Ref p0);
	@Virtual @Overload void writeRowId(Java_sql_RowId p0);
	@Virtual @Overload void writeSQLXML(Java_sql_SQLXML p0);
	@Virtual @Overload void writeShort(int p0);
	@Virtual @Overload void writeString(String p0);
	@Virtual @Overload void writeStruct(Java_sql_Struct p0);
	@Virtual @Overload void writeTime(Java_sql_Time p0);
	@Virtual @Overload void writeTimestamp(Java_sql_Timestamp p0);
	@Virtual @Overload void writeURL(Java_net_URL p0);
}

/* class java.sql.SQLPermission */
class Java_sql_SQLPermission extends Java_security_BasicPermission {
}
@Overload Java_sql_SQLPermission Java_sql_SQLPermission.new(String p0);
@Overload Java_sql_SQLPermission Java_sql_SQLPermission.new(String p0, String p1);

/* class java.sql.SQLRecoverableException */
class Java_sql_SQLRecoverableException extends Java_sql_SQLException {
}
@Overload Java_sql_SQLRecoverableException Java_sql_SQLRecoverableException.new();
@Overload Java_sql_SQLRecoverableException Java_sql_SQLRecoverableException.new(String p0);
@Overload Java_sql_SQLRecoverableException Java_sql_SQLRecoverableException.new(String p0, String p1);
@Overload Java_sql_SQLRecoverableException Java_sql_SQLRecoverableException.new(String p0, String p1, int p2);
@Overload Java_sql_SQLRecoverableException Java_sql_SQLRecoverableException.new(Java_lang_Throwable p0);
@Overload Java_sql_SQLRecoverableException Java_sql_SQLRecoverableException.new(String p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLRecoverableException Java_sql_SQLRecoverableException.new(String p0, String p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLRecoverableException Java_sql_SQLRecoverableException.new(String p0, String p1, int p2, Java_lang_Throwable p3);

/* class java.sql.SQLSyntaxErrorException */
class Java_sql_SQLSyntaxErrorException extends Java_sql_SQLNonTransientException {
}
@Overload Java_sql_SQLSyntaxErrorException Java_sql_SQLSyntaxErrorException.new();
@Overload Java_sql_SQLSyntaxErrorException Java_sql_SQLSyntaxErrorException.new(String p0);
@Overload Java_sql_SQLSyntaxErrorException Java_sql_SQLSyntaxErrorException.new(String p0, String p1);
@Overload Java_sql_SQLSyntaxErrorException Java_sql_SQLSyntaxErrorException.new(String p0, String p1, int p2);
@Overload Java_sql_SQLSyntaxErrorException Java_sql_SQLSyntaxErrorException.new(Java_lang_Throwable p0);
@Overload Java_sql_SQLSyntaxErrorException Java_sql_SQLSyntaxErrorException.new(String p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLSyntaxErrorException Java_sql_SQLSyntaxErrorException.new(String p0, String p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLSyntaxErrorException Java_sql_SQLSyntaxErrorException.new(String p0, String p1, int p2, Java_lang_Throwable p3);

/* class java.sql.SQLTimeoutException */
class Java_sql_SQLTimeoutException extends Java_sql_SQLTransientException {
}
@Overload Java_sql_SQLTimeoutException Java_sql_SQLTimeoutException.new();
@Overload Java_sql_SQLTimeoutException Java_sql_SQLTimeoutException.new(String p0);
@Overload Java_sql_SQLTimeoutException Java_sql_SQLTimeoutException.new(String p0, String p1);
@Overload Java_sql_SQLTimeoutException Java_sql_SQLTimeoutException.new(String p0, String p1, int p2);
@Overload Java_sql_SQLTimeoutException Java_sql_SQLTimeoutException.new(Java_lang_Throwable p0);
@Overload Java_sql_SQLTimeoutException Java_sql_SQLTimeoutException.new(String p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLTimeoutException Java_sql_SQLTimeoutException.new(String p0, String p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLTimeoutException Java_sql_SQLTimeoutException.new(String p0, String p1, int p2, Java_lang_Throwable p3);

/* class java.sql.SQLTransactionRollbackException */
class Java_sql_SQLTransactionRollbackException extends Java_sql_SQLTransientException {
}
@Overload Java_sql_SQLTransactionRollbackException Java_sql_SQLTransactionRollbackException.new();
@Overload Java_sql_SQLTransactionRollbackException Java_sql_SQLTransactionRollbackException.new(String p0);
@Overload Java_sql_SQLTransactionRollbackException Java_sql_SQLTransactionRollbackException.new(String p0, String p1);
@Overload Java_sql_SQLTransactionRollbackException Java_sql_SQLTransactionRollbackException.new(String p0, String p1, int p2);
@Overload Java_sql_SQLTransactionRollbackException Java_sql_SQLTransactionRollbackException.new(Java_lang_Throwable p0);
@Overload Java_sql_SQLTransactionRollbackException Java_sql_SQLTransactionRollbackException.new(String p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLTransactionRollbackException Java_sql_SQLTransactionRollbackException.new(String p0, String p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLTransactionRollbackException Java_sql_SQLTransactionRollbackException.new(String p0, String p1, int p2, Java_lang_Throwable p3);

/* class java.sql.SQLTransientConnectionException */
class Java_sql_SQLTransientConnectionException extends Java_sql_SQLTransientException {
}
@Overload Java_sql_SQLTransientConnectionException Java_sql_SQLTransientConnectionException.new();
@Overload Java_sql_SQLTransientConnectionException Java_sql_SQLTransientConnectionException.new(String p0);
@Overload Java_sql_SQLTransientConnectionException Java_sql_SQLTransientConnectionException.new(String p0, String p1);
@Overload Java_sql_SQLTransientConnectionException Java_sql_SQLTransientConnectionException.new(String p0, String p1, int p2);
@Overload Java_sql_SQLTransientConnectionException Java_sql_SQLTransientConnectionException.new(Java_lang_Throwable p0);
@Overload Java_sql_SQLTransientConnectionException Java_sql_SQLTransientConnectionException.new(String p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLTransientConnectionException Java_sql_SQLTransientConnectionException.new(String p0, String p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLTransientConnectionException Java_sql_SQLTransientConnectionException.new(String p0, String p1, int p2, Java_lang_Throwable p3);

/* class java.sql.SQLTransientException */
class Java_sql_SQLTransientException extends Java_sql_SQLException {
}
@Overload Java_sql_SQLTransientException Java_sql_SQLTransientException.new();
@Overload Java_sql_SQLTransientException Java_sql_SQLTransientException.new(String p0);
@Overload Java_sql_SQLTransientException Java_sql_SQLTransientException.new(String p0, String p1);
@Overload Java_sql_SQLTransientException Java_sql_SQLTransientException.new(String p0, String p1, int p2);
@Overload Java_sql_SQLTransientException Java_sql_SQLTransientException.new(Java_lang_Throwable p0);
@Overload Java_sql_SQLTransientException Java_sql_SQLTransientException.new(String p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLTransientException Java_sql_SQLTransientException.new(String p0, String p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLTransientException Java_sql_SQLTransientException.new(String p0, String p1, int p2, Java_lang_Throwable p3);

/* class java.sql.SQLWarning */
class Java_sql_SQLWarning extends Java_sql_SQLException {
	/*-- Method --*/
	@Virtual @Overload Java_sql_SQLWarning getNextWarning();
	@Virtual @Overload void setNextWarning(Java_sql_SQLWarning p0);
}
@Overload Java_sql_SQLWarning Java_sql_SQLWarning.new(String p0, String p1, int p2);
@Overload Java_sql_SQLWarning Java_sql_SQLWarning.new(String p0, String p1);
@Overload Java_sql_SQLWarning Java_sql_SQLWarning.new(String p0);
@Overload Java_sql_SQLWarning Java_sql_SQLWarning.new();
@Overload Java_sql_SQLWarning Java_sql_SQLWarning.new(Java_lang_Throwable p0);
@Overload Java_sql_SQLWarning Java_sql_SQLWarning.new(String p0, Java_lang_Throwable p1);
@Overload Java_sql_SQLWarning Java_sql_SQLWarning.new(String p0, String p1, Java_lang_Throwable p2);
@Overload Java_sql_SQLWarning Java_sql_SQLWarning.new(String p0, String p1, int p2, Java_lang_Throwable p3);

/* interface java.sql.SQLXML */
class Java_sql_SQLXML {
	/*-- Method --*/
	@Virtual @Overload void free();
	@Virtual @Overload Java_io_InputStream getBinaryStream();
	@Virtual @Overload Java_io_Reader getCharacterStream();
	@Virtual @Overload javax.xml.transform.Source getSource(Class p0);
	@Virtual @Overload String getString();
	@Virtual @Overload Java_io_OutputStream setBinaryStream();
	@Virtual @Overload Java_io_Writer setCharacterStream();
	@Virtual @Overload javax.xml.transform.Result setResult(Class p0);
	@Virtual @Overload void setString(String p0);
}

/* interface java.sql.Savepoint */
class Java_sql_Savepoint {
	/*-- Method --*/
	@Virtual @Overload int getSavepointId();
	@Virtual @Overload String getSavepointName();
}

/* interface java.sql.Statement */
class Java_sql_Statement {
	// implements java.sql.Wrapper, java.lang.AutoCloseable
	/*-- Method --*/
	@Virtual @Overload void addBatch(String p0);
	@Virtual @Overload void cancel();
	@Virtual @Overload void clearBatch();
	@Virtual @Overload void clearWarnings();
	@Virtual @Overload void close();
	@Virtual @Overload void closeOnCompletion();
	@Virtual @Overload boolean execute(String p0);
	@Virtual @Overload boolean execute(String p0, int p1);
	@Virtual @Overload boolean execute(String p0, int[] p1);
	@Virtual @Overload boolean execute(String p0, String[] p1);
	@Virtual @Overload int[] executeBatch();
	@Virtual @Overload Java_sql_ResultSet executeQuery(String p0);
	@Virtual @Overload int executeUpdate(String p0);
	@Virtual @Overload int executeUpdate(String p0, int p1);
	@Virtual @Overload int executeUpdate(String p0, int[] p1);
	@Virtual @Overload int executeUpdate(String p0, String[] p1);
	@Virtual @Overload Java_sql_Connection getConnection();
	@Virtual @Overload int getFetchDirection();
	@Virtual @Overload int getFetchSize();
	@Virtual @Overload Java_sql_ResultSet getGeneratedKeys();
	@Virtual @Overload int getMaxFieldSize();
	@Virtual @Overload int getMaxRows();
	@Virtual @Overload boolean getMoreResults();
	@Virtual @Overload boolean getMoreResults(int p0);
	@Virtual @Overload int getQueryTimeout();
	@Virtual @Overload Java_sql_ResultSet getResultSet();
	@Virtual @Overload int getResultSetConcurrency();
	@Virtual @Overload int getResultSetHoldability();
	@Virtual @Overload int getResultSetType();
	@Virtual @Overload int getUpdateCount();
	@Virtual @Overload Java_sql_SQLWarning getWarnings();
	@Virtual @Overload boolean isCloseOnCompletion();
	@Virtual @Overload boolean isClosed();
	@Virtual @Overload boolean isPoolable();
	@Virtual @Overload void setCursorName(String p0);
	@Virtual @Overload void setEscapeProcessing(boolean p0);
	@Virtual @Overload void setFetchDirection(int p0);
	@Virtual @Overload void setFetchSize(int p0);
	@Virtual @Overload void setMaxFieldSize(int p0);
	@Virtual @Overload void setMaxRows(int p0);
	@Virtual @Overload void setPoolable(boolean p0);
	@Virtual @Overload void setQueryTimeout(int p0);
}

/* interface java.sql.Struct */
class Java_sql_Struct {
	/*-- Method --*/
	@Virtual @Overload Object[] getAttributes();
	@Virtual @Overload Object[] getAttributes(Java_util_Map p0);
	@Virtual @Overload String getSQLTypeName();
}

/* class java.sql.Time */
class Java_sql_Time extends Java_util_Date {
	/*-- Method --*/
	@Virtual @Overload Java_sql_Time valueOf(String p0);
}
@Overload Java_sql_Time Java_sql_Time.new(int p0, int p1, int p2);
@Overload Java_sql_Time Java_sql_Time.new(long p0);

/* class java.sql.Timestamp */
class Java_sql_Timestamp extends Java_util_Date {
	/*-- Method --*/
	@Virtual @Overload boolean after(Java_sql_Timestamp p0);
	@Virtual @Overload boolean before(Java_sql_Timestamp p0);
	@Virtual @Overload int compareTo(Java_sql_Timestamp p0);
	@Virtual @Overload boolean equals(Java_sql_Timestamp p0);
	@Virtual @Overload int getNanos();
	@Virtual @Overload void setNanos(int p0);
	@Virtual @Overload Java_sql_Timestamp valueOf(String p0);
}
@Overload Java_sql_Timestamp Java_sql_Timestamp.new(int p0, int p1, int p2, int p3, int p4, int p5, int p6);
@Overload Java_sql_Timestamp Java_sql_Timestamp.new(long p0);

/* class java.sql.Types */
class Java_sql_Types {
}

/* interface java.sql.Wrapper */
class Java_sql_Wrapper {
	/*-- Method --*/
	@Virtual @Overload boolean isWrapperFor(Class p0);
	@Virtual @Overload Object unwrap(Class p0);
}


/*------------------------------------------------------------*/
/* short names */
BatchUpdateException = Java_sql_BatchUpdateException
Blob = Java_sql_Blob
CallableStatement = Java_sql_CallableStatement
ClientInfoStatus = Java_sql_ClientInfoStatus
Clob = Java_sql_Clob
Connection = Java_sql_Connection
DataTruncation = Java_sql_DataTruncation
DatabaseMetaData = Java_sql_DatabaseMetaData
Date = Java_sql_Date
Driver = Java_sql_Driver
DriverManager = Java_sql_DriverManager
DriverPropertyInfo = Java_sql_DriverPropertyInfo
NClob = Java_sql_NClob
ParameterMetaData = Java_sql_ParameterMetaData
PreparedStatement = Java_sql_PreparedStatement
PseudoColumnUsage = Java_sql_PseudoColumnUsage
Ref = Java_sql_Ref
ResultSet = Java_sql_ResultSet
ResultSetMetaData = Java_sql_ResultSetMetaData
RowId = Java_sql_RowId
RowIdLifetime = Java_sql_RowIdLifetime
SQLClientInfoException = Java_sql_SQLClientInfoException
SQLData = Java_sql_SQLData
SQLDataException = Java_sql_SQLDataException
SQLException = Java_sql_SQLException
SQLFeatureNotSupportedException = Java_sql_SQLFeatureNotSupportedException
SQLInput = Java_sql_SQLInput
SQLIntegrityConstraintViolationException = Java_sql_SQLIntegrityConstraintViolationException
SQLInvalidAuthorizationSpecException = Java_sql_SQLInvalidAuthorizationSpecException
SQLNonTransientConnectionException = Java_sql_SQLNonTransientConnectionException
SQLNonTransientException = Java_sql_SQLNonTransientException
SQLOutput = Java_sql_SQLOutput
SQLPermission = Java_sql_SQLPermission
SQLRecoverableException = Java_sql_SQLRecoverableException
SQLSyntaxErrorException = Java_sql_SQLSyntaxErrorException
SQLTimeoutException = Java_sql_SQLTimeoutException
SQLTransactionRollbackException = Java_sql_SQLTransactionRollbackException
SQLTransientConnectionException = Java_sql_SQLTransientConnectionException
SQLTransientException = Java_sql_SQLTransientException
SQLWarning = Java_sql_SQLWarning
SQLXML = Java_sql_SQLXML
Savepoint = Java_sql_Savepoint
Statement = Java_sql_Statement
Struct = Java_sql_Struct
Time = Java_sql_Time
Timestamp = Java_sql_Timestamp
Types = Java_sql_Types
Wrapper = Java_sql_Wrapper
