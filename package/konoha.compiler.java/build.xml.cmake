<project name="JavaKonoha" default="jar">
	<!-- directory / file definition -->
	<property name="source" value="${CMAKE_CURRENT_SOURCE_DIR}/src" />
	<property name="build" value="${CMAKE_CURRENT_BINARY_DIR}" />
	<property name="jarfile" value="jkonoha.jar" />

	<!-- ================================== -->
	<!--                BUILD               -->
	<!-- ================================== -->
	<target name="build">
		<mkdir dir="${CMAKE_CURRENT_BINARY_DIR}" />
		<javac srcdir="${CMAKE_CURRENT_SOURCE_DIR}/src" destdir="${CMAKE_CURRENT_BINARY_DIR}" debug="on"
			target="1.6" source="1.6" includeantruntime="false">
			<classpath path="${CMAKE_CURRENT_SOURCE_DIR}/third-party/asm-all-4.0.jar" />
			<include name="**/*.java" />
		</javac>
	</target>

	<!-- ================================== -->
	<!--            GENERATE JAR            -->
	<!-- ================================== -->
	<target name="jar" depends="build">
		<jar jarfile="jkonoha.jar">
			<fileset dir="${CMAKE_CURRENT_BINARY_DIR}" includes="**/*.class" />
			<zipfileset src="${CMAKE_CURRENT_SOURCE_DIR}/third-party/asm-all-4.0.jar" />
			<manifest>
				<attribute name="Main-Class" value="compiler.JavaKonoha" />
			</manifest>
		</jar>
	</target>

	<!-- ================================== -->
	<!--               CLEAN                -->
	<!-- ================================== -->
	<target name="clean">
		<delete dir="${CMAKE_CURRENT_BINARY_DIR}" />
		<delete file="jkonoha.jar" />
	</target>
</project>

